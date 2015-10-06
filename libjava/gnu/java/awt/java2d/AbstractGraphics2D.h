
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_awt_java2d_AbstractGraphics2D__
#define __gnu_java_awt_java2d_AbstractGraphics2D__

#pragma interface

#include <java/awt/Graphics2D.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace awt
      {
        namespace java2d
        {
            class AbstractGraphics2D;
            class ScanlineConverter;
            class ScanlineCoverage;
            class ShapeCache;
            class TextCacheKey;
        }
      }
    }
  }
  namespace java
  {
    namespace awt
    {
        class BasicStroke;
        class Color;
        class Composite;
        class Font;
        class FontMetrics;
        class Graphics;
        class Image;
        class Paint;
        class PaintContext;
        class Rectangle;
        class RenderingHints;
        class RenderingHints$Key;
        class Shape;
        class Stroke;
      namespace font
      {
          class FontRenderContext;
          class GlyphVector;
      }
      namespace geom
      {
          class AffineTransform;
      }
      namespace image
      {
          class BufferedImage;
          class BufferedImageOp;
          class ColorModel;
          class ImageObserver;
          class Raster;
          class RenderedImage;
          class WritableRaster;
        namespace renderable
        {
            class RenderableImage;
        }
      }
    }
    namespace text
    {
        class AttributedCharacterIterator;
    }
  }
}

class gnu::java::awt::java2d::AbstractGraphics2D : public ::java::awt::Graphics2D
{

public: // actually protected
  AbstractGraphics2D();
public:
  virtual void draw(::java::awt::Shape *);
  virtual jboolean drawImage(::java::awt::Image *, ::java::awt::geom::AffineTransform *, ::java::awt::image::ImageObserver *);
private:
  jboolean drawImageImpl(::java::awt::Image *, ::java::awt::geom::AffineTransform *, ::java::awt::image::ImageObserver *, ::java::awt::Rectangle *);
public:
  virtual void drawImage(::java::awt::image::BufferedImage *, ::java::awt::image::BufferedImageOp *, jint, jint);
  virtual void drawRenderedImage(::java::awt::image::RenderedImage *, ::java::awt::geom::AffineTransform *);
private:
  void drawRenderedImageImpl(::java::awt::image::RenderedImage *, ::java::awt::geom::AffineTransform *, ::java::awt::Rectangle *);
public:
  virtual void drawRenderableImage(::java::awt::image::renderable::RenderableImage *, ::java::awt::geom::AffineTransform *);
private:
  void drawRenderableImageImpl(::java::awt::image::renderable::RenderableImage *, ::java::awt::geom::AffineTransform *, ::java::awt::Rectangle *);
public:
  virtual void drawString(::java::lang::String *, jint, jint);
  virtual void drawString(::java::lang::String *, jfloat, jfloat);
  virtual void drawString(::java::text::AttributedCharacterIterator *, jint, jint);
  virtual void drawString(::java::text::AttributedCharacterIterator *, jfloat, jfloat);
  virtual void fill(::java::awt::Shape *);
  virtual jboolean hit(::java::awt::Rectangle *, ::java::awt::Shape *, jboolean);
  virtual void setComposite(::java::awt::Composite *);
  virtual void setPaint(::java::awt::Paint *);
  virtual void setStroke(::java::awt::Stroke *);
  virtual void setRenderingHint(::java::awt::RenderingHints$Key *, ::java::lang::Object *);
  virtual ::java::lang::Object * getRenderingHint(::java::awt::RenderingHints$Key *);
  virtual void setRenderingHints(::java::util::Map *);
  virtual void addRenderingHints(::java::util::Map *);
  virtual ::java::awt::RenderingHints * getRenderingHints();
  virtual void translate(jint, jint);
  virtual void translate(jdouble, jdouble);
  virtual void rotate(jdouble);
  virtual void rotate(jdouble, jdouble, jdouble);
  virtual void scale(jdouble, jdouble);
  virtual void shear(jdouble, jdouble);
  virtual void transform(::java::awt::geom::AffineTransform *);
  virtual void setTransform(::java::awt::geom::AffineTransform *);
  virtual ::java::awt::geom::AffineTransform * getTransform();
  virtual ::java::awt::Paint * getPaint();
  virtual ::java::awt::Composite * getComposite();
  virtual void setBackground(::java::awt::Color *);
  virtual ::java::awt::Color * getBackground();
  virtual ::java::awt::Stroke * getStroke();
  virtual void clip(::java::awt::Shape *);
  virtual ::java::awt::font::FontRenderContext * getFontRenderContext();
  virtual void drawGlyphVector(::java::awt::font::GlyphVector *, jfloat, jfloat);
  virtual ::java::awt::Graphics * create();
public: // actually protected
  virtual ::java::lang::Object * clone();
public:
  virtual ::java::awt::Color * getColor();
  virtual void setColor(::java::awt::Color *);
  virtual void setPaintMode();
  virtual void setXORMode(::java::awt::Color *);
  virtual ::java::awt::Font * getFont();
  virtual void setFont(::java::awt::Font *);
  virtual ::java::awt::FontMetrics * getFontMetrics(::java::awt::Font *);
  virtual ::java::awt::Rectangle * getClipBounds();
  virtual void clipRect(jint, jint, jint, jint);
  virtual void setClip(jint, jint, jint, jint);
  virtual ::java::awt::Shape * getClip();
  virtual void setClip(::java::awt::Shape *);
  virtual void copyArea(jint, jint, jint, jint, jint, jint);
  virtual void drawLine(jint, jint, jint, jint);
  virtual void drawRect(jint, jint, jint, jint);
  virtual void fillRect(jint, jint, jint, jint);
  virtual void clearRect(jint, jint, jint, jint);
  virtual void drawRoundRect(jint, jint, jint, jint, jint, jint);
  virtual void fillRoundRect(jint, jint, jint, jint, jint, jint);
  virtual void drawOval(jint, jint, jint, jint);
  virtual void fillOval(jint, jint, jint, jint);
  virtual void drawArc(jint, jint, jint, jint, jint, jint);
  virtual void fillArc(jint, jint, jint, jint, jint, jint);
  virtual void drawPolyline(JArray< jint > *, JArray< jint > *, jint);
  virtual void drawPolygon(JArray< jint > *, JArray< jint > *, jint);
  virtual void fillPolygon(JArray< jint > *, JArray< jint > *, jint);
  virtual jboolean drawImage(::java::awt::Image *, jint, jint, ::java::awt::image::ImageObserver *);
  virtual jboolean drawImage(::java::awt::Image *, jint, jint, jint, jint, ::java::awt::image::ImageObserver *);
  virtual jboolean drawImage(::java::awt::Image *, jint, jint, ::java::awt::Color *, ::java::awt::image::ImageObserver *);
  virtual jboolean drawImage(::java::awt::Image *, jint, jint, jint, jint, ::java::awt::Color *, ::java::awt::image::ImageObserver *);
  virtual jboolean drawImage(::java::awt::Image *, jint, jint, jint, jint, jint, jint, jint, jint, ::java::awt::image::ImageObserver *);
  virtual jboolean drawImage(::java::awt::Image *, jint, jint, jint, jint, jint, jint, jint, jint, ::java::awt::Color *, ::java::awt::image::ImageObserver *);
  virtual void dispose();
public: // actually protected
  virtual void fillShape(::java::awt::Shape *, jboolean);
  virtual ::java::awt::image::ColorModel * getColorModel() = 0;
  virtual ::java::awt::Rectangle * getDeviceBounds() = 0;
  virtual void rawDrawLine(jint, jint, jint, jint);
  virtual void rawDrawRect(jint, jint, jint, jint);
  virtual void rawClearRect(jint, jint, jint, jint);
  virtual void rawFillRect(jint, jint, jint, jint);
  virtual jboolean rawDrawImage(::java::awt::Image *, jint, jint, ::java::awt::image::ImageObserver *);
  virtual void rawCopyArea(jint, jint, jint, jint, jint, jint);
private:
  void copyAreaImpl(jint, jint, jint, jint, jint, jint);
public:
  virtual void renderScanline(jint, ::gnu::java::awt::java2d::ScanlineCoverage *);
public: // actually protected
  virtual void init();
  virtual ::java::awt::image::WritableRaster * getDestinationRaster();
  virtual void updateRaster(::java::awt::image::Raster *, jint, jint, jint, jint);
private:
  void updateOptimization();
  static ::java::awt::Rectangle * computeIntersection(jint, jint, jint, jint, ::java::awt::Rectangle *);
  void updateClip(::java::awt::geom::AffineTransform *);
  ::gnu::java::awt::java2d::ScanlineConverter * getScanlineConverter();
  void freeScanlineConverter(::gnu::java::awt::java2d::ScanlineConverter *);
  ::java::awt::PaintContext * getPaintContext();
public:
  static ::java::awt::Image * prepareImage(::java::awt::Image *, jint, jint);
public: // actually protected
  static ::java::util::WeakHashMap * imageCache;
private:
  static jboolean DEFAULT_TEXT_AA;
  static ::java::awt::Font * FONT;
  static const jint GV_CACHE_SIZE = 50;
  static ::gnu::java::awt::java2d::ShapeCache * shapeCache;
  static ::java::util::LinkedList * scanlineConverters;
  static ::java::util::Map * gvCache;
  static ::gnu::java::awt::java2d::TextCacheKey * searchTextKey;
public: // actually protected
  ::java::awt::geom::AffineTransform * __attribute__((aligned(__alignof__( ::java::awt::Graphics2D)))) transform__;
private:
  ::java::awt::Paint * paint;
  ::java::awt::PaintContext * paintContext;
  ::java::awt::Color * background;
  ::java::awt::Color * foreground;
  jboolean isForegroundColorNull;
  ::java::awt::Font * font;
  ::java::awt::Composite * composite;
  ::java::awt::Stroke * stroke;
  ::java::awt::Shape * clip__;
  ::java::awt::RenderingHints * renderingHints;
  ::java::awt::image::WritableRaster * destinationRaster;
  jboolean isOptimized;
  static ::java::awt::BasicStroke * STANDARD_STROKE;
  static ::java::util::HashMap * STANDARD_HINTS;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_awt_java2d_AbstractGraphics2D__
