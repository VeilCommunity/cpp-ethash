// Copyright 2018 Pawel Bylica.
// Licensed under the Apache License, Version 2.0. See the LICENSE file.

#pragma once

#include <ethash/ethash.hpp>

#include <cstring>

extern "C" void ethash_keccakf(uint64_t* state);

namespace ethash
{

inline void keccak_load_block_into_state(uint64_t* state, const uint64_t* block, size_t block_size)
{
    for (size_t i = 0; i < (block_size / sizeof(uint64_t)); ++i)
        state[i] ^= block[i];  // TODO: Add BE support.
}

template <size_t bits>
struct hash_selector
{
};

template <>
struct hash_selector<256>
{
    using type = hash256;
};
template <>
struct hash_selector<512>
{
    using type = hash512;
};

template <size_t bits>
inline typename hash_selector<bits>::type keccak(const uint64_t* data, size_t size)
{
    static constexpr size_t block_size = (1600 - bits * 2) / 8;
    static constexpr size_t block_words = block_size / sizeof(uint64_t);

    uint64_t state[25] = {};

    while (size >= block_words)
    {
        keccak_load_block_into_state(state, data, block_size);
        ethash_keccakf(state);
        data += block_words;
        size -= block_words;
    }

    // Final block:
    uint64_t block[block_words] = {};
    // Weirdly, GCC and clang are able to optimize memcpy better than for loop.
    std::memcpy(block, data, size * sizeof(uint64_t));

    // Padding:
    auto block_bytes = reinterpret_cast<unsigned char*>(block);
    block_bytes[size * sizeof(uint64_t)] = 0x01;
    block_bytes[block_size - 1] = 0x80;

    keccak_load_block_into_state(state, block, block_size);
    ethash_keccakf(state);

    typename hash_selector<bits>::type hash;
    std::memcpy(hash.bytes, state, sizeof(hash));
    return hash;
}

inline hash256 keccak256(const hash256& input)
{
    return keccak<256>(input.words, sizeof(input) / sizeof(uint64_t));
}

inline hash512 keccak512(const hash256& input)
{
    return keccak<512>(input.words, sizeof(input) / sizeof(uint64_t));
}

inline hash512 keccak512(const hash512& input)
{
    return keccak<512>(input.words, sizeof(input) / sizeof(uint64_t));
}

}
