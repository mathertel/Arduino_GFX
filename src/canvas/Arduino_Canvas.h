#include "../Arduino_DataBus.h"
#if !defined(LITTLE_FOOT_PRINT)

#ifndef _ARDUINO_CANVAS_H_
#define _ARDUINO_CANVAS_H_

#include "../Arduino_GFX.h"

class Arduino_Canvas : public Arduino_GFX
{
public:
  Arduino_Canvas(int16_t w, int16_t h, Arduino_G *output, int16_t output_x = 0, int16_t output_y = 0, uint8_t rotation = 0);
  ~Arduino_Canvas();

  bool begin(int32_t speed = GFX_NOT_DEFINED) override;
  void writePixelPreclipped(int16_t x, int16_t y, uint16_t color) override;
  void writeFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) override;
  void writeFastVLineCore(int16_t x, int16_t y, int16_t h, uint16_t color);
  void writeFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) override;
  void writeFastHLineCore(int16_t x, int16_t y, int16_t w, uint16_t color);
  void writeFillRectPreclipped(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) override;
  void drawIndexedBitmap(int16_t x, int16_t y, uint8_t *bitmap, uint16_t *color_index, int16_t w, int16_t h, int16_t x_skip = 0) override;
  void drawIndexedBitmap(int16_t x, int16_t y, uint8_t *bitmap, uint16_t *color_index, uint8_t chroma_key, int16_t w, int16_t h, int16_t x_skip = 0) override;
  void draw16bitRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap, int16_t w, int16_t h) override;
  void draw16bitRGBBitmapWithTranColor(int16_t x, int16_t y, uint16_t *bitmap, uint16_t transparent_color, int16_t w, int16_t h) override;
  void draw16bitBeRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap, int16_t w, int16_t h) override;
  void flush(bool force_flush = false) override;
  void flushQuad(bool force_flush = false);

  uint16_t *getFramebuffer();

protected:
  uint16_t *_framebuffer = nullptr;
  Arduino_G *_output = nullptr;
  int16_t _output_x, _output_y;
  int16_t MAX_X, MAX_Y;

  // for flushQuad() only
  uint16_t *_rowBuf = nullptr;

private:
};

#endif // _ARDUINO_CANVAS_H_

#endif // !defined(LITTLE_FOOT_PRINT)
