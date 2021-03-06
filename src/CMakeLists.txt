set(UnitsHeaders Basic/ScalarUnit.h Basic/Vector.h Basic/VectorUnit.h Basic/Point.h Basic/Position.h Basic/Matrix.h Basic/MatrixUnit.h Basic/Physics.h)
set(UnitsSourceFiles Basic/Vector.cpp Basic/VectorUnit.cpp Basic/Point.cpp Basic/Matrix.cpp Basic/MatrixUnit.cpp Basic/Physics.cpp)

add_library(Units STATIC ${UnitsSourceFiles})
target_include_directories(Units PUBLIC ./)
set(ModelsHeaders Models/PhysicalModel.h Models/DummyModel.h Models/Model_6DOF.h Models/PlaneState.h Models/AtmosphereModel.cpp)
set(ModelsSourceFiles Models/PhysicalModel.cpp Models/DummyModel.cpp Models/Model_6DOF.cpp Models/AtmosphereModel.h)

set(ControllerSourceFiles PlaneController.cpp)
set(ControllerHearder PlaneController.h)

set(SceneSourceFiles Scene/Geometry.cpp Scene/shaders.cpp Scene/Transform.cpp Scene/grader.cpp Scene/FixObj.cpp Scene/Scene.cpp)
set(SceneHearder Scene/Geometry.h Scene/shaders.h Scene/Transform.h Scene/grader.h Scene/FreeImage.h)

add_library(Scene STATIC ${SceneSourceFiles})
target_include_directories(Scene PUBLIC . )

target_link_libraries(Scene Units)
target_link_libraries(Scene glfw)
target_link_libraries(Scene glad)
target_link_libraries(Scene glm)
target_link_libraries(Scene SOIL)


add_library(Models STATIC ${ModelsSourceFiles})
target_include_directories(Models PUBLIC . )
target_link_libraries(Models Units)

add_library(Controller STATIC ${ControllerSourceFiles})
target_include_directories(Controller PUBLIC .)

target_link_libraries(Controller Units)
target_link_libraries(Controller glfw)
target_link_libraries(Controller glad)


add_subdirectory(Models/PlaneParts)

add_executable(main main.cpp)
target_link_libraries(main Scene)
target_link_libraries(main Models)
target_link_libraries(main Controller)
target_link_libraries(main glfw)
target_link_libraries(main glad)
target_link_libraries(main glm)
target_link_libraries(Scene SOIL)




