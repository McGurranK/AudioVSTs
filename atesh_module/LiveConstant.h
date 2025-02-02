/*
* ComponentMover.h
*/

#pragma once

/*
* GUI utility class for using the live constant to change a components size and position
*/

template <class JuceComponent, typename = typename std::enable_if<std::is_base_of<juce::Component, JuceComponent>::value, JuceComponent>::type>
class ComponentMover : public JuceComponent
                     , public juce::Timer
{
public:
    ComponentMover ()
    {
        startTimer (10);
    }
    
    ~ComponentMover() override
    {
        stopTimer();
    }
    
    void timerCallback() final
    {
        const auto xPos = JUCE_LIVE_CONSTANT (JuceComponent::getX());
        const auto yPos = JUCE_LIVE_CONSTANT (JuceComponent::getY());
        const auto width = JUCE_LIVE_CONSTANT (JuceComponent::getWidth());
        const auto height = JUCE_LIVE_CONSTANT (JuceComponent::getHeight());
        
        JuceComponent::setBounds (xPos, yPos, width, height);
    }
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComponentMover)
};
