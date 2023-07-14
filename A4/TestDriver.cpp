#include<iostream>
#include<vector>

#include "Rhombus.h"
#include "Rectangle.h"
#include "AcuteTriangle.h"
#include "RightTriangle.h"
#include "Canvas.h"

using std::cout;
using std::endl;

void drawHouse();      // draws front view of a house image

int main()
{
   drawHouse();  

   return 0;
}

// Using our four geometric shapes, 
// draws a pattern that looks like the front view of a house
void drawHouse()
{
   // create a vector of smart pointers to Shape 
   std::vector<std::unique_ptr<Shape>> shapeVec;

   // create a 47-row by 72-column Canvas
   Canvas houseCanvas(47, 72);
   houseCanvas.drawString(1, 10, "a geometric house: front view");

   shapeVec.push_back(std::make_unique<RightTriangle>(20, '\\', "Right half of roof"));
   Canvas roof_right_can = shapeVec.back()->draw();
   houseCanvas.overlap(roof_right_can, 4, 27);

   shapeVec.back()->setPen('/');
   Canvas roof_left_can = shapeVec.back()->draw().flip_horizontal();
   houseCanvas.overlap(roof_left_can, 4, 7);

   houseCanvas.drawString(23, 8,
      "[][][][][][][][][][][][][][][][][][][]");

   shapeVec.push_back(std::make_unique<Rectangle>(5, 1, '|', "left chimeny edge"));
   Canvas chimneyL = shapeVec.back()->draw();
   houseCanvas.overlap(chimneyL, 14, 12);

   shapeVec.push_back(std::make_unique<Rectangle>(4, 1, '|', "right chimeny edge"));
   Canvas chimneyR = shapeVec.back()->draw();
   houseCanvas.overlap(chimneyR, 14, 13);

   shapeVec.push_back(std::make_unique<Rectangle>(11, 1, 'I', "antenna stem"));
   Canvas antenna_stem = shapeVec.back()->draw();
   houseCanvas.overlap(antenna_stem, 11, 45);

   shapeVec.push_back(std::make_unique<RightTriangle>(5, '=', "Right antenna wing"));
   Canvas antenna_Q1 = shapeVec.back()->draw();
   Canvas antenna_Q2 = antenna_Q1.flip_horizontal();
   Canvas antenna_Q3 = antenna_Q2.flip_vertical();
   Canvas antenna_Q4 = antenna_Q1.flip_vertical();
   houseCanvas.overlap(antenna_Q3, 11, 40);
   houseCanvas.overlap(antenna_Q4, 11, 46);

   shapeVec.push_back(std::make_unique<Rectangle>(18, 1, '[', "vertical left and right brackets"));
   Canvas wall = shapeVec.back()->draw();
   houseCanvas.overlap(wall, 24, 8);
   houseCanvas.overlap(wall, 24, 44);

   shapeVec.back()->setPen(']'); // use the same wall shape
   houseCanvas.overlap(wall, 24, 9);
   houseCanvas.overlap(wall, 24, 45);

   shapeVec.push_back(std::make_unique<Rectangle>(1, 66, '-', "horizontal lines depicting the ground"));
   Canvas line = shapeVec.back()->draw();
   for (int c = 1; c <= 6; c++)
   {
      houseCanvas.overlap(line, 40 + c, 7 - c);
   }
   houseCanvas.drawString(40, 8,
      "[][][][][][][][][][][][][][][][][][][]");
   houseCanvas.drawString(41, 8,
      "[][][][][][][][][][][][][][][][][][][]");

   shapeVec.push_back(std::make_unique<Rectangle>(1, 12, '/', "door step"));
   Canvas door_step = shapeVec.back()->draw();
   houseCanvas.overlap(door_step, 39, 21);

   shapeVec.push_back(std::make_unique<Rectangle>(12, 12, '|', "door"));
   Canvas door = shapeVec.back()->draw();
   houseCanvas.overlap(door, 27, 21);

   shapeVec.push_back(std::make_unique<Rectangle>(1, 10, '=', "door top/bottom edge"));
   Canvas door_edge = shapeVec.back()->draw();
   houseCanvas.overlap(door_edge, 27, 22);
   houseCanvas.overlap(door_edge, 38, 22);

   shapeVec.push_back(std::make_unique<Rectangle>(1, 1, 'O', "door knob"));
   Canvas door_knob = shapeVec.back()->draw();
   houseCanvas.overlap(door_knob, 33, 22);

   houseCanvas.drawString(26, 25, "5421");

   shapeVec.push_back(std::make_unique<Rhombus>(5, '+', "left window"));
   Canvas window = shapeVec.back()->draw();
   houseCanvas.overlap(window, 28, 14);
   houseCanvas.overlap(window, 28, 35);

   shapeVec.push_back(std::make_unique<Rectangle>(5, 3, 'H', "tree trunk"));
   Canvas tree_trunk = shapeVec.back()->draw();
   houseCanvas.overlap(tree_trunk, 36, 60);

   shapeVec.push_back(std::make_unique<AcuteTriangle>(7, '*', "top level leaves"));
   Canvas leaves = shapeVec.back()->draw();
   houseCanvas.overlap(leaves, 21, 58);

   shapeVec.push_back(std::make_unique<AcuteTriangle>(11, '*', "middle level leaves"));
   Canvas middleLeaves = shapeVec.back()->draw();
   houseCanvas.overlap(middleLeaves, 23, 56);

   shapeVec.push_back(std::make_unique<AcuteTriangle>(19, '*', "bottom level leaves"));
   Canvas bottomLeaves = shapeVec.back()->draw();
   houseCanvas.overlap(bottomLeaves, 26, 52);

   houseCanvas.drawString(13, 11, "\\||/");
   houseCanvas.drawString(12, 11, "_/\\_");

   // finally, reveal the house image
   cout << houseCanvas;

   for (const auto& shp : shapeVec)
   {
      cout << *shp << endl;
   }

   return;
}

