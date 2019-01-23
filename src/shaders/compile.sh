glslangValidator -V src/shaders/shader.vert
mv vert.spv shaders

glslangValidator -V src/shaders/shader.frag
mv frag.spv shaders
