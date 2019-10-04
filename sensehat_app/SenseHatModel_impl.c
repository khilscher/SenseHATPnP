﻿/*******************************************************************************************
 * This code was automatically generated by Digital Twin Code Generator tool 0.6.2.
 *
 * You need to add your implementation here to:
 *    - get telemetry data from device/sensor
 *    - set read-only property data
 *    - handle read-write property callback
 *    - process device command
 *
 * Generated Date: Friday, October 4, 2019
 *******************************************************************************************/

#include "SenseHatModel_impl.h"
#include "utilities/digitaltwin_serializer.h"
#include "utilities/sensehat_interface.h"
#include "utilities/deviceinfo_interface.h"

#include "stdio.h"
#include "stdlib.h"

#define Payload_Buffer_Size 256

void SendTelemetry_Succeeded_Callback(const char* interfaceName, const char* telemetryName)
{
    // If needed, put your business logic here to handle the confirmation of the delivery for device telemetry on success.

    LogInfo("DigitalTwin successfully delivered telemetry message for %s::%s", interfaceName, telemetryName);
}

void SendTelemetry_Error_Callback(const char* interfaceName, const char* telemetryName)
{
    // If needed, put your business logic here to handle the confirmation of the delivery for device telemetry on failure.

    LogInfo("DigitalTwin failed to deliver telemetry message for %s::%s", interfaceName, telemetryName);
}

void ReportProperty_Succeeded_Callback(const char* interfaceName, const char* propertyName)
{
    // If needed, put your business logic here to handle the result callback reporting property on success.

    LogInfo("DigitalTwin successfully report writable property for %s::%s", interfaceName, propertyName);
}

void ReportProperty_Error_Callback(const char* interfaceName, const char* propertyName)
{
    // If needed, put your business logic here to handle the result callback of reporting property on failure.

    LogInfo("DigitalTwin failed to report writable property for %s::%s", interfaceName, propertyName);
}

double Sensehat_Telemetry_ReadTemperature()
{

    FILE *fp;
    char value[20];
    double rtn_value;

    fp = popen("/usr/bin/python3 /home/pi/get_temperature.py", "r");

    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }

    fgets(value, sizeof value, fp);

    printf("%s", value);

    sscanf(value, "%lf", &rtn_value);

    pclose(fp);

    return rtn_value;

}

double Sensehat_Telemetry_ReadHumidity()
{

    FILE *fp;
    char value[20];
    double rtn_value;

    fp = popen("/usr/bin/python3 /home/pi/get_humidity.py", "r");

    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }

    fgets(value, sizeof value, fp);

    printf("%s", value);

    sscanf(value, "%lf", &rtn_value);

    pclose(fp);

    return rtn_value;

}

double Sensehat_Telemetry_ReadPressure()
{

    FILE *fp;
    char value[20];
    double rtn_value;

    fp = popen("/usr/bin/python3 /home/pi/get_pressure.py", "r");

    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }

    fgets(value, sizeof value, fp);

    printf("%s", value);

    sscanf(value, "%lf", &rtn_value);

    pclose(fp);

    return rtn_value;

}

DIGITALTWIN_COMMAND_RESULT Sensehat_Command_Show_message(char* message, unsigned int* statusCode)
{

    FILE *fp;
    char path[1035];
    char cmd[50];

    strcpy(cmd, "/usr/bin/python3 /home/pi/show_message.py ");

    strcat(cmd, message);

    fp = popen(cmd, "r");

    if (fp == NULL) {
      printf("Failed to run command\n" );
      return DIGITALTWIN_COMMAND_ERROR;
    }

    pclose(fp);

    LogInfo("Parameter: message = %s", message);

    *statusCode = 200;

    LogInfo("Execute 'show_message' command successfully");

    return DIGITALTWIN_COMMAND_OK;

}

char* DeviceInfo_Property_GetManufacturer()
{
    // TODO: provide implementation here
    return "Raspberrypi.org";
}

char* DeviceInfo_Property_GetModel()
{
    // TODO: provide implementation here
    return "Sense HAT";
}

char* DeviceInfo_Property_GetSwVersion()
{
    // TODO: provide implementation here
    return "1.0";
}

char* DeviceInfo_Property_GetOsName()
{
    // TODO: provide implementation here
    return "Raspbian (Stretch)";
}

char* DeviceInfo_Property_GetProcessorArchitecture()
{
    // TODO: provide implementation here
    return "ARMv8";
}

char* DeviceInfo_Property_GetProcessorManufacturer()
{
    // TODO: provide implementation here
    return "Broadcom BCM2837B0, Cortex-A53 (ARMv8) 64-bit SoC @ 1.4GHz";
}

long DeviceInfo_Property_GetTotalStorage()
{
    // TODO: provide implementation here
    return 8000L;
}

long DeviceInfo_Property_GetTotalMemory()
{
    // TODO: provide implementation here
    return 1000L;
}

