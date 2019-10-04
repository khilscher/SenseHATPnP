﻿/*********************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.2.
 *
 * Generated Date: Friday, October 4, 2019
 *********************************************************************************************/

#ifndef PNP_DEVICE
#define PNP_DEVICE

#include "digitaltwin_device_client_ll.h"
#include "digitaltwin_interface_client.h"
#include "azure_c_shared_utility/threadapi.h"
#include "azure_c_shared_utility/tickcounter.h"
#include "utilities/digitaltwin_client_helper.h"

#include "utilities/sensehat_interface.h"

#include "utilities/deviceinfo_interface.h"

#include "SenseHatModel_impl.h"

#ifdef __cplusplus
extern "C"
{
#endif

int pnp_device_initialize(const char* connectionString, const char* trustedCert);

void pnp_device_run();

void pnp_device_close();

#ifdef __cplusplus
}
#endif

#endif // PNP_DEVICE