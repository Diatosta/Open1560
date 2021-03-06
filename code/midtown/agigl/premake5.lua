arts_component "agigl"
    files {
        "glpipe.cpp",
        "glpipe.h",
        "gltexdef.cpp",
        "gltexdef.h",
        "glview.cpp",
        "glview.h",
        "glbitmap.cpp",
        "glbitmap.h",
        "glrsys.cpp",
        "glrsys.h",
        "glerror.cpp",
        "glerror.h",

        "wglext.h",
    }

    links {
        "glad",
        "opengl32",
    }

    includeGlad()
    includeWgl()
