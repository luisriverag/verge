// Copyright (c) 2009-2017 The Bitcoin Core developers
// Copyright (c) 2018-2025 The Verge Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <wallet/test/wallet_test_fixture.h>

#include <rpc/server.h>
#include <wallet/db.h>

WalletTestingSetup::WalletTestingSetup(const std::string& chainName):
    TestingSetup(chainName), m_wallet("mock", WalletDatabase::CreateMock())
{
    bool fFirstRun;
    m_wallet.LoadWallet(fFirstRun);
    RegisterValidationInterface(&m_wallet);

    RegisterWalletRPCCommands(tableRPC);
}

WalletTestingSetup::~WalletTestingSetup()
{
    UnregisterValidationInterface(&m_wallet);
}
