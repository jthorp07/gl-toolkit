# GLTK: A Toolkit for OpenGL-Based Engines

> [!WARNING]
> This is a personal project that includes hand-rolling mathematical constructs and formulae. While I intend to do so as optimally and portably as possible for the scope of the project, there will certainly be both performance and flexibility limitations when compared to more robust solutions like [GLM](https://github.com/g-truc/glm).

## Feature Roadmap

Public facing documentation will probably be put on the backburner until a minimum viable product release is possible. Until then, the primary public facing documentation will be this roadmap and other indicators of progress toward a first limited release.

### Version 0.0.1 Progress

- [ ] Foundational graphics math
    - [ ] Vector Math (Arithmetic Operators, Dot, Cross)
        - [ ] 2D Vector
        - [x] 3D Vector
        - [ ] 4D Vector
    - [ ] Matrix Math (Multiplication, Determinant, Inverse)
        - [ ] 2x2 Matrix
        - [ ] 3x3 Matrix
        - [ ] 4x4 Matrix
- [ ] Rendering
    - [ ] OpenGL Interface
        - [ ] Vertex Buffer
        - [ ] Vertex Array
        - [ ] Element Buffer
    - [ ] Shader Interface
        - [ ] Default Vertex/Fragment Shaders
        - [ ] "Bring Your Own Shaders" Option
    - [ ] Internal Model
        - [ ] Geometric Meshes
            - [ ] Base Mesh
            - [ ] Rectangular Prism
        - [ ] Model/View/Perspective Rendering Logic
        - [ ] Transformation Functions for Model
            - [ ] Translate
            - [ ] Scale
            - [ ] Rotate
- [ ] Other Core Logic
    - [ ] Render Loop
    - [ ] Event System
    - [ ] Scene Architecture
        - [ ] Basic Camera
        - [ ] Basic Lighting
- [ ] Demo Application
    - [ ] Pass OpenGL Context to Engine
    - [ ] Create Hardcoded Scene
    - [ ] Run Engine & Display Scene
