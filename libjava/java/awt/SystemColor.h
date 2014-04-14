
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_SystemColor__
#define __java_awt_SystemColor__

#pragma interface

#include <java/awt/Color.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class PaintContext;
        class Rectangle;
        class RenderingHints;
        class SystemColor;
      namespace geom
      {
          class AffineTransform;
          class Rectangle2D;
      }
      namespace image
      {
          class ColorModel;
      }
    }
  }
}

class java::awt::SystemColor : public ::java::awt::Color
{

  SystemColor(jint);
public:
  jint getRGB();
  ::java::awt::PaintContext * createContext(::java::awt::image::ColorModel *, ::java::awt::Rectangle *, ::java::awt::geom::Rectangle2D *, ::java::awt::geom::AffineTransform *, ::java::awt::RenderingHints *);
  ::java::lang::String * toString();
private:
  static const jlong serialVersionUID = 4503142729533789064LL;
public:
  static const jint DESKTOP = 0;
  static const jint ACTIVE_CAPTION = 1;
  static const jint ACTIVE_CAPTION_TEXT = 2;
  static const jint ACTIVE_CAPTION_BORDER = 3;
  static const jint INACTIVE_CAPTION = 4;
  static const jint INACTIVE_CAPTION_TEXT = 5;
  static const jint INACTIVE_CAPTION_BORDER = 6;
  static const jint WINDOW = 7;
  static const jint WINDOW_BORDER = 8;
  static const jint WINDOW_TEXT = 9;
  static const jint MENU = 10;
  static const jint MENU_TEXT = 11;
  static const jint TEXT = 12;
  static const jint TEXT_TEXT = 13;
  static const jint TEXT_HIGHLIGHT = 14;
  static const jint TEXT_HIGHLIGHT_TEXT = 15;
  static const jint TEXT_INACTIVE_TEXT = 16;
  static const jint CONTROL = 17;
  static const jint CONTROL_TEXT = 18;
  static const jint CONTROL_HIGHLIGHT = 19;
  static const jint CONTROL_LT_HIGHLIGHT = 20;
  static const jint CONTROL_SHADOW = 21;
  static const jint CONTROL_DK_SHADOW = 22;
  static const jint SCROLLBAR = 23;
  static const jint INFO = 24;
  static const jint INFO_TEXT = 25;
  static const jint NUM_COLORS = 26;
private:
  static JArray< jint > * colors;
public:
  static ::java::awt::SystemColor * desktop;
  static ::java::awt::SystemColor * activeCaption;
  static ::java::awt::SystemColor * activeCaptionText;
  static ::java::awt::SystemColor * activeCaptionBorder;
  static ::java::awt::SystemColor * inactiveCaption;
  static ::java::awt::SystemColor * inactiveCaptionText;
  static ::java::awt::SystemColor * inactiveCaptionBorder;
  static ::java::awt::SystemColor * window;
  static ::java::awt::SystemColor * windowBorder;
  static ::java::awt::SystemColor * windowText;
  static ::java::awt::SystemColor * menu;
  static ::java::awt::SystemColor * menuText;
  static ::java::awt::SystemColor * text;
  static ::java::awt::SystemColor * textText;
  static ::java::awt::SystemColor * textHighlight;
  static ::java::awt::SystemColor * textHighlightText;
  static ::java::awt::SystemColor * textInactiveText;
  static ::java::awt::SystemColor * control;
  static ::java::awt::SystemColor * controlText;
  static ::java::awt::SystemColor * controlHighlight;
  static ::java::awt::SystemColor * controlLtHighlight;
  static ::java::awt::SystemColor * controlShadow;
  static ::java::awt::SystemColor * controlDkShadow;
  static ::java::awt::SystemColor * scrollbar;
  static ::java::awt::SystemColor * info;
  static ::java::awt::SystemColor * infoText;
  static ::java::lang::Class class$;
};

#endif // __java_awt_SystemColor__
