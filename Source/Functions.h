#pragma once

extern bool GODMODE;
void godmode(bool toggle);

void RequestControlOfEnt(Entity entity);
Hash $(std::string str);
Vector3 rot_to_direction(Vector3*rot);
Vector3 add(Vector3*vectorA, Vector3*vectorB);
Vector3 multiply(Vector3*vector, float x);
float get_distance(Vector3*pointA, Vector3*pointB);
float get_vector_length(Vector3*vector);
void notifyBottom(char * fmt, ...);
void notifyBottom(std::string str);
void notifyMap(char * fmt, ...);
void notifyMap(std::string str);
void notifyCenter(char * fmt, ...);
void notifyCenter(std::string str);
void update_status_text();
void draw_rect(float A_0, float A_1, float A_2, float A_3, int A_4, int A_5, int A_6, int A_7);
void draw_menu_line(std::string caption, float lineWidth, float lineHeight, float lineTop, float lineLeft, float textLeft, bool active, bool title, bool rescaleText = true);
char* CharKeyboard(char* windowName, int maxInput, char* defaultText);
int NumberKeyboard();
void notifyleft(char* msg);
void TPtoCoord(float CoordsX, float CoordsyY, float CoordsZ);