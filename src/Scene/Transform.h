#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

typedef glm::mat3 mat3 ;
typedef glm::mat4 mat4 ; 
typedef glm::vec3 vec3 ; 
typedef glm::vec4 vec4 ; 
const float pi = 3.14159265 ;


class Transform  
{
	public:
		Transform();
		virtual ~Transform();
		static void left(float degrees, vec3& eye, vec3& up);
		static void up(float degrees, vec3& eye, vec3& up);
		static mat4 lookAt(vec3 eye, vec3 up);
		static mat3 rotate(const float degrees, const vec3& axis) ;
};
