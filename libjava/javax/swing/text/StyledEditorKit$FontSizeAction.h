
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_text_StyledEditorKit$FontSizeAction__
#define __javax_swing_text_StyledEditorKit$FontSizeAction__

#pragma interface

#include <javax/swing/text/StyledEditorKit$StyledTextAction.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
      namespace event
      {
          class ActionEvent;
      }
    }
  }
  namespace javax
  {
    namespace swing
    {
      namespace text
      {
          class StyledEditorKit$FontSizeAction;
      }
    }
  }
}

class javax::swing::text::StyledEditorKit$FontSizeAction : public ::javax::swing::text::StyledEditorKit$StyledTextAction
{

public:
  StyledEditorKit$FontSizeAction(::java::lang::String *, jint);
  virtual void actionPerformed(::java::awt::event::ActionEvent *);
private:
  jint __attribute__((aligned(__alignof__( ::javax::swing::text::StyledEditorKit$StyledTextAction)))) size;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_text_StyledEditorKit$FontSizeAction__
