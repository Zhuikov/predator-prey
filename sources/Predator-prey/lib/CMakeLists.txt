#lib

set(
        LIB_SOURCE_FILES

        animal.cpp animal.h
        badboundary.h
        brain.cpp brain.h
        badfield.h
        badnum.h
        coordinates.cpp coordinates.h
        field.cpp field.h
        grass.cpp grass.h
        model.cpp model.h
        modelapi.h
        movement.cpp movement.h
        predator.cpp predator.h
        prey.cpp prey.h
        preysbrain.cpp predatorsbrain.h
        predatorsbrain.cpp predatorsbrain.h
        sense.cpp sense.h
        settings.cpp settings.h
        unit.h
        units.cpp units.h
)

add_library(lib STATIC ${LIB_SOURCE_FILES})
