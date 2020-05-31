
#pragma once

#if defined(ARDUINO_ARCH_AVR)

    namespace TMCStepper_n {
        typedef uint8_t PinDef;

        class TMCPin {
        public:
            explicit TMCPin(const uint8_t _pin);
            void mode(const uint8_t mode) const;
            bool read() const;
            operator bool() const {
                return read();
            }

        protected:
            volatile uint8_t* const port = nullptr;
            uint8_t const bitMask;
        };

        class OutputPin : public TMCPin {
        public:
            OutputPin(const uint8_t _pin);
            void write(const bool state) const;
        };

        typedef TMCPin InputPin;
    }

#elif defined(ARDUINO_ARCH_SAM)

    namespace TMCStepper_n {

        typedef uint32_t PinDef;

        class TMCPin {
        public:
            explicit TMCPin(const uint32_t _pin);
            void mode(const uint8_t mode) const;
            bool read() const;
            operator bool() const { return read(); }
            operator uint32_t() const { return pin; }
        protected:
            uint32_t const pin;
        };

        class OutputPin : public TMCPin {
        public:
            OutputPin(const uint32_t _pin);
            void write(const bool state) const;
        };

        typedef TMCPin InputPin;
    }

#elif defined(TARGET_LPC1768)

    namespace TMCStepper_n {

        typedef uint16_t PinDef;

        class TMCPin {
        public:
            explicit TMCPin(const uint16_t _pin) : pin(_pin) {}
            void mode(const uint8_t mode);
            bool read() const;
            operator bool() const { return read(); }
            operator uint16_t() const { return pin; }
        protected:
            uint16_t const pin;
            static constexpr uint8_t pinDelay = 60;
        };

        class OutputPin : public TMCPin {
        public:
            OutputPin(const uint16_t _pin) : TMCPin(_pin) {}
            void write(const bool state) const;
        };

        typedef TMCPin InputPin;
    }

#elif defined(ARDUINO)

    namespace TMCStepper_n {

        typedef uint8_t PinDef;

        class TMCPin {
        public:
            explicit TMCPin(const uint8_t _pin);
            void mode(const uint8_t mode) const;
            bool read() const;
            operator bool() const {
                return read();
            }

        protected:
            uint8_t const pin;
        };

        class OutputPin : public TMCPin {
        public:
            OutputPin(const uint8_t _pin);
            void write(const bool state) const;
        };

        typedef TMCPin InputPin;
    }

#endif

#ifndef HIGH
    #define HIGH 1
#endif
#ifndef LOW
    #define LOW 0
#endif
#ifndef INPUT
    #define INPUT  0x00
#endif
#ifndef INPUT_PULLUP
    #define INPUT_PULLUP  0x01
#endif
#ifndef OUTPUT
    #define OUTPUT 0x01
#endif
#if !defined(MSBFIRST) && !(defined(ARDUINO_ARCH_SAM) || defined(ARDUINO_ARCH_SAMD))
    #define MSBFIRST 1
#endif
#ifndef SPI_MODE3
    #define SPI_MODE3 0
#endif
