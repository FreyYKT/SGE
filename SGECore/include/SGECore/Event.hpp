#pragma once

#include <functional>
#include <array>

namespace SGE {

    enum class EventType
    {
        WindowResize = 0,
        WindowClose,

        KeyPressed,
        KeyReleased,

        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,



        EventsCount
    };

    struct BaseEvent
    {
        virtual ~BaseEvent() = default;
        virtual EventType getType() const = 0;
    };


    class EventDispatcher
    {
    public:
        template<typename EventType>
        void addEventListener(std::function<void(EventType&)> callback)
        {
            auto baseCallback = [func = std::move(callback)](BaseEvent& e)
            {
                if (e.getType() == EventType::type)
                {
                    func(static_cast<EventType&>(e));
                }
            };
            eventCallbacks[static_cast<size_t>(EventType::type)] = std::move(baseCallback);
        }

        void dispatch(BaseEvent& event)
        {
            auto& callback = eventCallbacks[static_cast<size_t>(event.getType())];
            if (callback)
            {
                callback(event);
            }
        }

    private:
        std::array<std::function<void(BaseEvent&)>, static_cast<size_t>(EventType::EventsCount)> eventCallbacks;
    };


    struct EventMouseMoved : public BaseEvent
    {
        EventMouseMoved(const double new_x, const double new_y)
            : x(new_x)
            , y(new_y)
        {
        }

        virtual EventType getType() const override
        {
            return type;
        }

        double x;
        double y;

        static const EventType type = EventType::MouseMoved;
    };

    struct EventWindowResize : public BaseEvent
    {
        EventWindowResize(const unsigned int new_width, const unsigned int new_height)
            : width(new_width)
            , height(new_height)
        {
        }

        virtual EventType getType() const override
        {
            return type;
        }

        unsigned int width;
        unsigned int height;

        static const EventType type = EventType::WindowResize;
    };

    struct EventWindowClose : public BaseEvent
    {
        virtual EventType getType() const override
        {
            return type;
        }

        static const EventType type = EventType::WindowClose;
    };

}