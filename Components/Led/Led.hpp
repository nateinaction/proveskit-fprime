// ======================================================================
// \title  Led.hpp
// \author nate
// \brief  hpp file for Led component implementation class
// ======================================================================

#ifndef Components_Led_HPP
#define Components_Led_HPP
#include <Os/Mutex.hpp>

#include "Components/Led/LedComponentAc.hpp"

namespace Components {

  class Led :
    public LedComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct Led object
      Led(
          const char* const compName //!< The component name
      );

      //! Destroy Led object
      ~Led();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for run
      //!
      //! Port receiving calls from the rate group
      void run_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          NATIVE_UINT_TYPE context //!< The call order
      ) override;

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command BLINKING_ON_OFF
      //!
      //! Command to turn on or off the blinking LED
      void BLINKING_ON_OFF_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          Fw::On on_off //!< Indicates whether the blinking should be on or off
      ) override;

      //! Emit parameter updated EVR
      //!
      void parameterUpdated(FwPrmIdType id /*!< The parameter ID*/
      ) override;

      Os::Mutex lock; //! Protects our data from thread race conditions
      Fw::On state; //! Keeps track if LED is on or off
      U64 transitions; //! The number of on/off transitions that have occurred from FSW boot up
      U32 count; //! Keeps track of how many ticks the LED has been on for
      bool blinking; //! Flag: if true then LED blinking will occur else no blinking will happen
  };

}

#endif
