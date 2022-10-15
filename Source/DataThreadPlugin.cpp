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

// API docs: https://open-ephys.github.io/gui-docs/Developer-Guide/Open-Ephys-Plugin-API/Data-Threads.html
// Sample code: https://github.com/sccn/liblsl/blob/master/examples/ReceiveDataInChunks.cpp

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
    // TODO: For each inlet + optional TTL_event inlet pair
    //  std::size_t num_read = inlet->pull_chunk_multiplexed(float *data_buffer, double *timestamp_buffer,
    //		std::size_t buff_samps*chans, std::size_t buff_samps, double timeout = 0.0);
    //  .. similar for TTL_event inlet...
    //  .. TODO: Check to see if we need to transpose data_buffer into scaled_samples
    //  .. TODO: Find out what the common time base is, if any, and convert timestamps as needed.
    //  sourceBuffers[ix]->addToBuffer(scaled_samples, scaled_numbers, timestamps, event_codes, num_read);
    return true;
}

bool LSLInletPlugin::foundInputSource()
{
    // TODO: For each entry in GUI settings, call lsl::resolve_stream
    // TODO: Create an inlet for each and store the inlet in a private container.
    // TODO: Need to decide if we will do inlet.set_postprocessing(lsl::post_ALL);
    return true;
}

bool LSLInletPlugin::startAcquisition()
{
    // TODO: For each inlet:
    //  Pre-allocate buffers
    //  - std::vector<std::vector<T>> chunk and std::vector<double> timestamps
    //  inlet.open_stream();
    //  This begins buffering so the next call to pull_chunk should retrieve data.
    return true;
}

bool LSLInletPlugin::stopAcquisition()
{
    // TODO: for each inlet: inlet.close_stream();
    return true;
}


void LSLInletPlugin::updateSettings(OwnedArray<ContinuousChannel>* continuousChannels,
    OwnedArray<EventChannel>* eventChannels,
    OwnedArray<SpikeChannel>* spikeChannels,
    OwnedArray<DataStream>* sourceStreams,
    OwnedArray<DeviceInfo>* devices,
    OwnedArray<ConfigurationObject>* configurationObjects)
{
    sourceStreams->clear();
    continuousChannels->clear();
    eventChannels->clear();

    // TODO: For each inlet,
    //  Get lsl::stream_info info = inlet->info(),
    //   If the info.nominal_srate() != 0 then build the DataStream::Settings for that inlet.
    //   Note that any irregular rate inlets with int dtype will have to be attached to a regular-rate
    //   inlet in a single DataStream. i.e., we need at least 1 regular rate inlet for each event inlet.
    /*

    DataStream::Settings settings
            {
                    info.name(), // stream name, get from info.name()
                    "description",   // stream description
                    "identifier",    // stream identifier, get from info.source_id() if exists
                    info.nominal_srate()          // stream sample rate, info.nominal_srate()
            };

    DataStream* stream = new DataStream(settings);

    sourceStreams->add(stream); // add pointer to owned array

    lsl::xml_element desc = info.desc();
    // TODO: Unfortunately there aren't any great C++ examples for parsing the xml info to get channel names.
    //  The best I could find is in Python: https://github.com/intheon/stream_viewer/blob/a48d38b72ef95b0eac35f7903924facd4be6f197/stream_viewer/data/stream_lsl.py#L159-L174

    for (int i = 0; i < numChannels; i++)
    {
        ContinuousChannel::Settings settings{
                ContinuousChannel::Type::ELECTRODE, // channel type
                "CH" + String(i+1), // channel name
                "description",      // channel description
                "identifier",       // channel identifier
                0.195,              // channel bitvolts scaling
                stream              // associated data stream
        };

        continuousChannels->add(new ContinuousChannel(settings));
    }

    EventChannel::Settings settings{
            EventChannel::Type::TTL, // channel type (must be TTL)
            "Device Event Channel",  // channel name
            "description",           // channel description
            "identifier",            // channel identifier
            stream,                  // associated data stream
            8                        // maximum number of TTL lines
    };

    eventChannels->add(new EventChannel(settings));
    */
}


void LSLInletPlugin::resizeBuffers()
{

}


std::unique_ptr<GenericEditor> LSLInletPlugin::createEditor(SourceNode* sn)
{
    // https://open-ephys.github.io/gui-docs/Tutorials/How-To-Make-Your-Own-Plugin.html#adding-ui-components-to-the-editor

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
