#include <LCUI.h>


void OnButtonClick(LCUI_Widget self, LCUI_WidgetEvent e, void *arg)
{
    LCUI_Widget text = e->data;
    
    TextView_SetText(text, "Hello, LCUI!");
}


int main(void)
{
	
	LCUI_Widget root;
    LCUI_Widget text;
	LCUI_Widget button;
	
	
	
    LCUI_Init();
	root = LCUIWidget_GetRoot();
	 
    text = LCUIWidget_New("textview");					//textview is a origin for text, it will be used to find widget
	button = LCUIWidget_New("button");
	
	
    TextView_SetTextW(text, L"Hello, World!");			//set text for $text
	Button_SetTextW(button, L"Change");					//set text for button
	
	
    Widget_BindEvent(button, "click", OnButtonClick, text, NULL);		//binding click event for button
	
	
    Widget_Append(root, button);						//append button in root
	Widget_Append(root, text);							//combine text to root, Widget_  is the pattern for operating widget

	
    return LCUI_Main();
	
	
	
}
