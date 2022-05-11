#include <string>
#include <iostream>
#include <vector>
#include <GL/gl.h>
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
        GLuint textureId;
        bool isFromObj;
        vec4 position;
        vec4 direction;
        mat4 model;

    public:
        BaseObj(string path, float x=0, float y=0, float z=0){
            if( ezLoader(path.c_str(), vertices, uvs, normals)){
                std::cout << "succesfully loaded obj file\n";
                isFromObj = true;
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

        Base &translate(float x, float y, float z){
            // translate position by x, y, z
            //         <          translation matrix            > * <vecpos>
            position = glm::translate(glm::mat4(), vec3(x, y, z)) * position;
            return static_cast<Base&>(*this);
        }

        Base &rotate(float degrees, float x=0, float y=1, float z=0){
            direction = glm::rotate(glm::mat4(), glm::radians(degrees), vec3(x, y, z)) * direction;
            return static_cast<Base&>(*this);
        }

        Base &scale(float x=1, float y=1, float z=1){
            position = glm::scale(vec3(x, y, z)) * position;
            return static_cast<Base&>(*this);
        }

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

        }
};