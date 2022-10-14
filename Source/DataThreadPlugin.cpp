/*
 ------------------------------------------------------------------

 This file is part of the Open Ephys GUI
 Copyright (C) 2022 Open Ephys

 ------------------------------------------------------------------

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 */

#include "DataThreadPlugin.h"

#include "DataThreadPluginEditor.h"

#include "lsl_cpp.h"

LSLInletPlugin::LSLInletPlugin(SourceNode* sn) : DataThread(sn)
{

}


LSLInletPlugin::~LSLInletPlugin()
{

}

bool LSLInletPlugin::updateBuffer()
{
    // https://open-ephys.github.io/gui-docs/Developer-Guide/Open-Ephys-Plugin-API/Data-Threads.html
    // TODO: inlet->pull chunk
    // TODO: add to buffer
    // dataBuffer->addToBuffer(scaled_samples, scaled_numbers, timestamps, event_codes, numRead)
    return true;
}

bool LSLInletPlugin::foundInputSource()
{
    // TODO: Create resolver
    return true;
}

bool LSLInletPlugin::startAcquisition()
{
    // TODO: Create inlet(s)
    return true;
}

bool LSLInletPlugin::stopAcquisition()
{
    // TODO: Destroy inlet(s)
    return true;
}


void LSLInletPlugin::updateSettings(OwnedArray<ContinuousChannel>* continuousChannels,
    OwnedArray<EventChannel>* eventChannels,
    OwnedArray<SpikeChannel>* spikeChannels,
    OwnedArray<DataStream>* sourceStreams,
    OwnedArray<DeviceInfo>* devices,
    OwnedArray<ConfigurationObject>* configurationObjects)
{


}


void LSLInletPlugin::resizeBuffers()
{

}


std::unique_ptr<GenericEditor> LSLInletPlugin::createEditor(SourceNode* sn)
{
    
    std::unique_ptr<DataThreadPluginEditor> editor = std::make_unique<DataThreadPluginEditor>(sn);

    return editor;

}

void LSLInletPlugin::handleBroadcastMessage(String msg)
{


}

String LSLInletPlugin::handleConfigMessage(String msg)
{

    return "";
}
