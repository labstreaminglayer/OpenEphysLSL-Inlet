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

DataThreadPlugin::DataThreadPlugin(SourceNode* sn) : DataThread(sn)
{

}


DataThreadPlugin::~DataThreadPlugin()
{

}

bool DataThreadPlugin::updateBuffer()
{
    return true;
}

bool DataThreadPlugin::foundInputSource()
{
    return true;
}

bool DataThreadPlugin::startAcquisition()
{
    return true;
}

bool DataThreadPlugin::stopAcquisition()
{
    return true;
}


void DataThreadPlugin::updateSettings(OwnedArray<ContinuousChannel>* continuousChannels,
    OwnedArray<EventChannel>* eventChannels,
    OwnedArray<SpikeChannel>* spikeChannels,
    OwnedArray<DataStream>* sourceStreams,
    OwnedArray<DeviceInfo>* devices,
    OwnedArray<ConfigurationObject>* configurationObjects)
{


}


void DataThreadPlugin::resizeBuffers()
{

}


std::unique_ptr<GenericEditor> DataThreadPlugin::createEditor(SourceNode* sn)
{
    
    std::unique_ptr<DataThreadPluginEditor> editor = std::make_unique<DataThreadPluginEditor>(sn);

    return editor;

}

void DataThreadPlugin::handleBroadcastMessage(String msg)
{


}

String DataThreadPlugin::handleConfigMessage(String msg)
{

    return "";
}
