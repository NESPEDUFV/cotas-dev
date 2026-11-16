/*
 * Copyright (c) 2008 INRIA
 *
 * SPDX-License-Identifier: GPL-2.0-only
 *
 * Author: Mathieu Lacage <mathieu.lacage@sophia.inria.fr>
 */

#include "cotas-helper.h"

#include "ns3/address-utils.h"
#include "ns3/cotas.h"
#include "ns3/context-consumer.h"
#include "ns3/context-provider.h"
#include "ns3/generic-server.h"
#include "ns3/uinteger.h"

namespace ns3
{

CoTaSHelper::CoTaSHelper()
    : ApplicationHelper(CoTaS::GetTypeId())
{
}

CoTaSHelper::CoTaSHelper(uint16_t port)
    : CoTaSHelper()
{
    SetAttribute("Port", UintegerValue(port));
}

CoTaSHelper::CoTaSHelper(const Address& address)
    : CoTaSHelper()
{
    SetAttribute("Local", AddressValue(address));
}

GenericServerHelper::GenericServerHelper()
    : ApplicationHelper(CoTaS::GetTypeId())
{
}

GenericServerHelper::GenericServerHelper(uint16_t port)
    : GenericServerHelper()
{
    SetAttribute("Port", UintegerValue(port));
}

GenericServerHelper::GenericServerHelper(const Address& address)
    : GenericServerHelper()
{
    SetAttribute("Local", AddressValue(address));
}

ContextProviderHelper::ContextProviderHelper()
    : ApplicationHelper(ContextProvider::GetTypeId())
{
}

ContextProviderHelper::ContextProviderHelper(const Address& address)
    : ContextProviderHelper()
{
    SetAttribute("Remote", AddressValue(address));
}

ContextProviderHelper::ContextProviderHelper(const Address& address, uint16_t port)
    : ContextProviderHelper(addressUtils::ConvertToSocketAddress(address, port))
{
}

ContextConsumerHelper::ContextConsumerHelper()
    : ApplicationHelper(ContextConsumer::GetTypeId())
{
}

ContextConsumerHelper::ContextConsumerHelper(const Address& address)
    : ContextConsumerHelper()
{
    SetAttribute("Remote", AddressValue(address));
}

ContextConsumerHelper::ContextConsumerHelper(const Address& address, uint16_t port)
    : ContextConsumerHelper(addressUtils::ConvertToSocketAddress(address, port))
{
}

} // namespace ns3
