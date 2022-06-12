//========================================================
// date/author    : 2022/06/12 @chrmlinux03
// update/author  : 2022/06/12 @chrmlinux03
//--------------------------------------------------------
// license        : MIT
// system					: trapezoidal control using moving average
//========================================================

#ifndef __TRAPEZOID_HPP__
#define __TRAPEZOID_HPP__

#include <Arduino.h>

class TrapeZoid {

  public:

    //========================================
    // de/constractor
    //========================================
    TrapeZoid() {}
    ~TrapeZoid() {}

    //========================================
    // begin
    //========================================
    void begin(int dtcnt) {
      _dtcnt = dtcnt;
      begin();
    }
    void begin(void) {
      set(_dtcnt);
    }

    //========================================
    // end
    //========================================
    void end(void) {
      free(_fdt);
    }

    //========================================
    // set
    //========================================
    void set(int dtcnt) {
      _dtcnt = dtcnt;
      _fdt = new float[_dtcnt];
      _idx = 0;
      memset(_fdt, 0x0, sizeof(_fdt));
    }

    //========================================
    // idx
    //========================================
    uint16_t idx(void) {
      return _idx;
    }


    //========================================
    // update
    //========================================
    float update(float dt) {
      float mave = 0.0;
      float sum = 0.0;

      _fdt[_idx] = dt;
      for (int i = 0; i < _dtcnt; i++) {
        sum += _fdt[i];
      }
      mave = sum / _dtcnt;
      _idx = (_idx + 1) % _dtcnt;

      return mave;
    }

    //========================================
    // private
    //========================================

  private:

    float *_fdt;
    uint16_t _dtcnt = 10;
    uint16_t _idx = 0;

};

#endif
