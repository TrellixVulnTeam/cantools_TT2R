/*
Copyright(c) 2019 Cedric Jimenez

This file is part of cantools.

cantools is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

cantools is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with cantools.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "CanAdapterPluginApi.h"
#include "LoopbackCanAdapterController.h"

#include <stdlib.h>

/** \brief Get the plugin's type */
static const char* DYN_LINK_API CAN_ADAPTER_GetType(void)
{
    return CAN_ADAPTER_PLUGIN_TYPE;
}

/** \brief Get the plugin's name */
static const char* DYN_LINK_API CAN_ADAPTER_GetName(void)
{
    return "loopback_adapter";
}

/** \brief Get the plugin's version */
static const char* DYN_LINK_API CAN_ADAPTER_GetVersion(void)
{
    return "1.0";
}

/** \brief Get the plugin's parameters */
static const PluginParameter* DYN_LINK_API CAN_ADAPTER_GetParams(void)
{
    static const PluginParameter plugin_params[] = 
    {
        {NULL, NULL, NULL}
    };

    return plugin_params;
}

/** \brief Get the adapter's enumerator */
static CanAdapterEnumerator* DYN_LINK_API CAN_ADAPTER_GetEnumerator(void)
{
    // No enumerator
    return NULL;
}

/** \brief Release the adapter's enumerator */
void DYN_LINK_API CAN_ADAPTER_ReleaseEnumerator(void)
{
    // Nothing to do
}

/** \brief Create a can controller from the specified parameters */
static CanAdapterController* DYN_LINK_API CAN_ADAPTER_CreateController(const char* parameters)
{
    (void)parameters;
    
    // Instanciate controller
    CanAdapterController* controller = malloc(sizeof(CanAdapterController));
    controller->open = &CanAdapterController_Open;
    controller->close = &CanAdapterController_Close;
    controller->configure = &CanAdapterController_Configure;
    controller->get_capabilities = &CanAdapterController_GetCapabilities;
    controller->start = &CanAdapterController_Start;
    controller->stop = &CanAdapterController_Stop;
    controller->send = &CanAdapterController_Send;
    controller->get_error_msg = &CanAdapterController_GetErrorMsg;
    controller->controller = CanAdapterController_Allocate();
    return controller;
}

/** \brief Release a can controller */
static void DYN_LINK_API CAN_ADAPTER_ReleaseController(CanAdapterController* controller)
{
    CanAdapterController_Release(controller->controller);
    free(controller);
}


/** \brief CAN adapter's functions */
static const CanAdapterPluginFuncs can_adapter_funcs = {
                                                        &CAN_ADAPTER_GetEnumerator,
                                                        &CAN_ADAPTER_ReleaseEnumerator,
                                                        &CAN_ADAPTER_CreateController,
                                                        &CAN_ADAPTER_ReleaseController
                                                       };

/** \brief Plugin's generic functions */
static const PluginGenericFuncs plugin_generic_funcs = {
                                                        &CAN_ADAPTER_GetType,
                                                        &CAN_ADAPTER_GetName,
                                                        &CAN_ADAPTER_GetVersion,
                                                        &CAN_ADAPTER_GetParams,
                                                        &can_adapter_funcs
                                                       };


/** \brief Get the plugin's functions */
DYN_LINK_EXPORT const PluginGenericFuncs* DYN_LINK_API PLUGIN_GetFuncs()
{
    return &plugin_generic_funcs;
}