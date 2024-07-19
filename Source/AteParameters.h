/*
* Ate Parameter struct for easy access to parametes
*/

#pragma once

struct AteParameterIDs final
{
    juce::String mixID { "MIX" };
    juce::String inputGainID { "INPUT" };

    juce::String delayTimeID { "TIME" };
    juce::String delayfeedBackAmountID { "FGAIN" };
    
    juce::String filterCuttOffID { "CUTT" };
    juce::String filterQID { "Q" };
    juce::String filterTypeID { "TIME" };
};

struct Parameters final
{
    Parameters (juce::AudioProcessor& ProcessorRef) : parameterValueTree (ProcessorRef, nullptr, "PARAMS", createLayout())
    {
        inputGainPtr = parameterValueTree.getParameter (parameterIDS.inputGainID);
        mixPtr = parameterValueTree.getParameter (parameterIDS.mixID);
        
        cuttoffPtr = parameterValueTree.getParameter (parameterIDS.filterCuttOffID);
        qPtr = parameterValueTree.getParameter (parameterIDS.filterQID);
        filterTypePtr = parameterValueTree.getParameter (parameterIDS.filterTypeID);
        
        timePtr = parameterValueTree.getParameter (parameterIDS.delayTimeID);
        delayAmount = parameterValueTree.getParameter (parameterIDS.delayfeedBackAmountID);
    }

    
    AteParameterIDs parameterIDS;
    juce::AudioProcessorValueTreeState parameterValueTree;
  
    juce::RangedAudioParameter* inputGainPtr { nullptr };
    juce::RangedAudioParameter* mixPtr { nullptr };

    juce::RangedAudioParameter* cuttoffPtr { nullptr };
    juce::RangedAudioParameter* qPtr { nullptr };
    juce::RangedAudioParameter* filterTypePtr { nullptr };
    
    juce::RangedAudioParameter* timePtr { nullptr };
    juce::RangedAudioParameter* delayAmount { nullptr };
    
private:
    
    juce::AudioProcessorValueTreeState::ParameterLayout createLayout()
    {
        juce::AudioProcessorValueTreeState::ParameterLayout parameterLayout;
    
        parameterLayout.add (std::make_unique<juce::AudioParameterFloat> (parameterIDS.mixID, "Mix", 0.0f, 1.0f, 1.0f));
        parameterLayout.add (std::make_unique<juce::AudioParameterFloat> (parameterIDS.inputGainID, "Input Gain", -80.f, 40.0f, 0.0f));

        parameterLayout.add (std::make_unique<juce::AudioParameterFloat> (parameterIDS.delayTimeID, "time", 1.f, 10000.0f, 1.0f));
        parameterLayout.add (std::make_unique<juce::AudioParameterFloat> (parameterIDS.delayfeedBackAmountID, "Input Gain", -40.f, 40.0f, 0.0f));
        
        parameterLayout.add (std::make_unique<juce::AudioParameterFloat> (parameterIDS.filterCuttOffID,"cutt", 20.f, 20000.0f, 20000.0f));
        parameterLayout.add (std::make_unique<juce::AudioParameterFloat> (parameterIDS.filterQID, "q", 0.0f, 10.0f, 1.0f));
        parameterLayout.add (std::make_unique<juce::AudioParameterChoice> (parameterIDS.filterTypeID, "Filter Type", juce::StringArray {"Low Pass", "High Pass", "Band"}, 0));

        return parameterLayout;
    }
    
};
