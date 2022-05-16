#include <string>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../Loader/obj_loader.hpp"

using std::string, std::vector;
using glm::vec3, glm::vec2, glm::vec4, glm::mat4;


template <class Base>
class BaseObj{
    protected:
        vector<vec3> vertices;
        vector<vec2> uvs;
        vector<vec3> normals;
        vec3 position;
        vec3 direction;
        mat4 model;
        GLuint vertex_buffer;
        GLuint uv_buffer;
        GLuint normal_buffer;
        GLuint vaID;
        bool isFromObj;

        void initVAO(){
            std::cout << "initting vao...\n";
            std::cout << "generating vertex buffer...\n";
            std::cout << glGenBuffers << std::endl;
            glGenBuffers(1, &vertex_buffer);
            glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
            glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
            std::cout << "generating uv buffer...\n";
            std::cout << glGenBuffers << std::endl;
            glGenBuffers(1, &uv_buffer);
            std::cout << "p..\n";
            glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
            std::cout << "p..\n";
            glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(float), &uvs[0], GL_STATIC_DRAW);
            std::cout << "generating normal buffer...\n";
            std::cout << glGenBuffers << std::endl;
            glGenBuffers(1, &normal_buffer);
            glBindBuffer(GL_ARRAY_BUFFER, normal_buffer);
            glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(float), &normals[0], GL_STATIC_DRAW);

            std::cout << "populating vertex array...\n";
            glGenVertexArrays(1, &vaID);
            glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
            glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*) 0);
            glBindBuffer(GL_ARRAY_BUFFER, normal_buffer);
            glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

            std::cout << "unbinding...\n";
            //unbind
            glBindVertexArray(0); 
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            glDisableVertexAttribArray(0);
        }
    
    public:
        BaseObj(string path, float x=0, float y=0, float z=0){
            if( ezLoader(path.c_str(), vertices, uvs, normals)){
                std::cout << "succesfully loaded obj file\n";
                std::cout << vertices.size() << " " << uvs.size() << " "<< normals.size() << std::endl;
                isFromObj = true;
                // initVAO();
                std::cout << "succesfully init vao\n";
            }
            else{
                std::cout << "failed to load " << path << "\n";
            }
            position = vec4(x, y, z, 0);
        }
        BaseObj(float x=0 , float y=0, float z=0){
            position = vec4(x, y, z, 0);
        }
        ~BaseObj(){}


        // Base &translate(float x, float y, float z){
        //     // translate position by x, y, z
        //     //         <          translation matrix            > * <vecpos>
        //     mat4 asd = glm::translate(mat4(), vec3(x, y, z));
        //     position = glm::translate(mat4(), vec3(x, y, z)) * position;
        //     return static_cast<Base&>(*this);
        // }

        // Base &rotate(float degrees, float x=0, float y=1, float z=0){
        //     direction = glm::rotate(mat4(), glm::radians(degrees), vec3(x, y, z)) * direction;
        //     return static_cast<Base&>(*this);
        // }

        // Base &scale(float x=1, float y=1, float z=1){
        //     position = glm::scale(vec3(x, y, z)) * position;
        //     return static_cast<Base&>(*this);
        // }

    public:
        float get_x(){ return this->xyz[0];}
        float get_y(){ return this->xyz[1];}
        float get_z(){ return this->xyz[2];}

};

class Truk: public BaseObj<Truk>{
    public:
        Truk(string path, float x=0, float y=0, float z=0){
            BaseObj(path, x, y, z);
        }
        
};

class Suzanne: public BaseObj<Suzanne>{
    public:
        Suzanne(string path, float x=0, float y=0, float z=0){
            BaseObj(path, x, y, z);
        }
        
        void draw(){
            // glEnableVertexAttribArray(0);
            // glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
            // glDrawArrays(GL_TRIANGLES, 0, vertices.size());
            // glDisableVertexAttribArray(0);
            // glBindVertexArray(vaID);

            // glUniform1i(textureID, 2);
            // mat4 test = glm::translate(mat4(), position);
            // glUniformMatrix4fv(matrixID, 1, GL_FALSE, &test[0][0]);
            // glUniformMatrix4fv(modelMatID, 1, GL_FALSE, &test[0][0]);
            // glDrawArrays(GL_TRIANGLES, 0, vertices.size());
        }
};