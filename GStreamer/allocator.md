# GstAllocator

- the GstAllocator is used to create new memory
- # include <gst/gstmemory.h>
- # include <gst/gstobject.h>

- parameters to control the allocation of memory
    - flags : flags to control allocation
    - align : the desired alignmen of the memory
    - prefix : the desired prefix
    - padding : the desired padding

- GstAllocator
    - map & unmap
    - copy
    - share
    - is_span
    - map_full & unmap_full

- GstAllocatorClass
    - object_class
    - alloc
    - free
