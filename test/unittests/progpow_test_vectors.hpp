// ethash: C/C++ implementation of Ethash, the Ethereum Proof of Work algorithm.
// Copyright 2018-2019 Pawel Bylica.
// Licensed under the Apache License, Version 2.0.

/// @file
/// ProgPoW test vectors.

#pragma once

namespace  // In anonymous namespace to allow including in multiple compilation units.
{
/// Defines a test case for ProgPoW hash() function.
struct progpow_hash_test_case
{
    int block_number;
    const char* header_hash_hex;
    const char* nonce_hex;
    const char* mix_hash_hex;
    const char* final_hash_hex;
};

progpow_hash_test_case progpow_hash_test_cases[] = {
        {0, "0000000000000000000000000000000000000000000000000000000000000000", "0000000000000000",
                "b1388e12e9898029a487f5534225c2ea8bd79c6ef6754db0405809f53d83c497",
                "3d2f6484ee555362e9d8e2ca54fb99741e755e849f9900ef84ad65aa3c935bd1"},
        {49, "63155f732f2bf556967f906155b510c917e48e99685ead76ea83f4eca03ab12b", "0000000006ff2c47",
                "a1574df5d1b9ddee0b357c2147422fed087308acd1a64e453f26a1c8c6a4c38c",
                "856b47c0683695810667b71056bb42696b6d67039f17dc49c72b0175fc1b96c4"},
        {50, "9e7248f20914913a73d80a70174c331b1d34f260535ac3631d770e656b5dd922", "00000000076e482e",
                "ae3a0f800b0228630e30d21a8e8fba67836997642af9de8179261a4a614fc182",
                "a56e213ff5e85bd2a9d13463b9b4965dfe9b133c8d857e78adb04121631b8b4d"},
        {99, "de37e1824c86d35d154cf65a88de6d9286aec4f7f10c3fc9f0fa1bcc2687188d", "000000003917afab",
                "e17cc5853e71e5dbbda14fc649f538a98f613767d05e5c4981b1e3c1d923de5c",
                "f1722578712b4e6068d1fc8f02a9b87c792bed0d478e6d4a1f12fb739dc5a731"},
        {29950, "ac7b55e801511b77e11d52e9599206101550144525b5679f2dab19386f23dcce", "005d409dbc23a62a",
                "8547cd5d4581078fae0de67ae3193f1988ecb91daab069a3d9240aa152be93f9",
                "1d12348a6e9312dadd2e5370b540f649d9ac65edad2f85119bcd47c4d9eed978"},
        {29999, "e43d7e0bdc8a4a3f6e291a5ed790b9fa1a0948a2b9e33c844888690847de19f5", "005db5fa4c2a3d03",
                "e450f6c0fbe64d4f7141c47d80d0daffd968346fba3fffaa03ccf48c4fe1334a",
                "498f3b5c4f3c43df7095789e9d6b35fd41e3d0336903e36b9a88ea7362adbde8"},
        {30000, "d34519f72c97cae8892c277776259db3320820cb5279a299d0ef1e155e5c6454", "005db8607994ff30",
                "4759b7f019021a1122558c3c26fbb5c535a8ee97176807dd32c5e4146b3bf495",
                "67df7441a1619a8c3b6d29d6091539ac8d8798de02ebfb2d1f325ae471079c7c"},
        {30049, "8b6ce5da0b06d18db7bd8492d9e5717f8b53e7e098d9fef7886d58a6e913ef64", "005e2e215a8ca2e7",
                "83894b92a4aa3515385cf64caac6344da746f94e618fc43318e20025314d48c4",
                "d98a0f252b395423fda9683f44ebb6e2bff27df922200d019b4e4b18ebbaaf02"},
        {30050, "c2c46173481b9ced61123d2e293b42ede5a1b323210eb2a684df0874ffe09047", "005e30899481055e",
                "ef2f1437b524ac90d28903b24d383fd90b9a27c5f77602764a6f75d5b61ef4d2",
                "4973473ec676f61f7b642f8d76b25c60ffa493c638e45901ca14ac9be72d4c31"},
        {30099, "ea42197eb2ba79c63cb5e655b8b1f612c5f08aae1a49ff236795a3516d87bc71", "005ea6aef136f88b",
                "905dbec5a4f429c3241790a0db3d6a396b60b7d32d941ad339bcb64c83bd0ad4",
                "b91f1b116d3d8d2371918bf2493cf303a8d8bb212354400be41b4beaf249ce8c"},
        {59950, "49e15ba4bf501ce8fe8876101c808e24c69a859be15de554bf85dbc095491bd6", "02ebe0503bd7b1da",
                "7af9edb92b01d217d6c16fb89284c015241ae6c41bcce5de1033e3cd614ce283",
                "8c3377369640d659ed2880981e076cae3b608833fb43756de652d5a9cf692ff7"},
        {59999, "f5c50ba5c0d6210ddb16250ec3efda178de857b2b1703d8d5403bd0f848e19cf", "02edb6275bd221e3",
                "9b15bf5432694aac0055a9877398fadd93647f3259c99dcec7d642e20a767a98",
                "b76e39cdd6c598c5de49e01c74fc5c432767103876f556d00e85afa624a6fee5"},
        {170915, "5b3e8dfa1aafd3924a51f33e2d672d8dae32fa528d8b1d378d6e4db0ec5d665d", "0000000044975727",
                "33dbc4dafb1e717486cef269937d562e6c2fa32baa7951ba68371b4ea655fdbd",
                "38e25f94ec38886d38f34121bf0025bb0e296e3f5fb8742c1f37bf153e210f14"},
        {170915, "5b3e8dfa1aafd3924a51f33e2d672d8dae32fa528d8b1d378d6e4db0ec5d665d", "00000000502F578A",
                "d47488b728109d75b7e07435e0f94772191bfc0051c348a84becb4860c5cb58b",
                "074ac1f1d1d08110288579c61f95c1aa657e3bf89ab0ae49fd19ab67076a8271"},

};
}  // namespace
