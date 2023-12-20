# GstObject/GstElement

- GstStateChange
- GstElementFlags
- Gst_Element_error_withh_details
- Gst_Element_error
- Gst_Element_warning_with_details
- Gst_Element_warning
- Gst_Element_info_with_defails
- Gst_Element_info
- Gst_State_get_lock
- Gst_State_get_cond

    - struct _GstElement
    - struct _GstElementClass

- class structure of Fields
    - parent_class : GstObjectClass
    - metadata : gpointer
    - elementfactory : GstElementFacory that creates these elements
    - padtemplates : a GList of GstPadTemplate
    - numpadtemplates : the number of padtemplated
    - pad_templ_cookie : changed whenever the padtemplates change