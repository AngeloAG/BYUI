"""
Author: Alberto Angelo Arellano Gaona
Date: 1/23/2022
Description: 
During this prove milestone and the next prove assignment, you will write a Python program that draws a semi-realistic outdoor scene in a computer window. Your program can draw any outdoor scene that you like as long as it meets these requirements:

The scene must be outdoor and include part of the sky.
The sky must have clouds.
The scene must include repetitive objects, such as blades of grass, trees, leaves on a tree, birds, flowers, insects, fish, pickets in a fence, dashed lines on a road, buildings, bales of hay, snowmen, snowflakes, or icicles.
"""

from draw2d import \
    start_drawing, draw_line, draw_oval, draw_arc, \
    draw_rectangle, draw_polygon, draw_text, finish_drawing
import random


def main():
    print("drawLandscape Running")

    # Width and height of the scene in pixels
    aaag_scene_width = 800
    aaag_scene_height = 500

    # Call the start_drawing function in the draw2d.py
    # library which will open a window and create a canvas.
    aaag_canvas = start_drawing("Scene", aaag_scene_width, aaag_scene_height)

    # Call your drawing functions such
    # as draw_sky and draw_ground here.
    aaag_draw_sky(aaag_canvas, aaag_scene_width, aaag_scene_height)

    aaag_ground_height_dividend = random.randint(2, 4)
    aaag_ground_level = aaag_scene_height / aaag_ground_height_dividend

    aaag_draw_clouds(aaag_canvas, aaag_scene_width,
                     aaag_ground_level, aaag_scene_height)
    aaag_draw_ground(
        aaag_canvas, aaag_scene_width, aaag_ground_level)

    aaag_draw_trees(aaag_canvas, aaag_ground_level)

    # Call the finish_drawing function
    # in the draw2d.py library.
    finish_drawing(aaag_canvas)


def aaag_draw_sky(aaag_canvas, aaag_scene_width, aaag_scene_height):
    """This function creates a sky background in the canvas provided in the argument"""
    aaag_sky_color = aaag_generate_random_color_for("sky")
    draw_rectangle(aaag_canvas, 0, 0, aaag_scene_width,
                   aaag_scene_height, fill=aaag_sky_color)


def aaag_draw_ground(aaag_canvas, aaag_scene_width, aaag_ground_height):
    """This function creates a ground for the scene width different heights  and random colors returns the ground level generated"""
    aaag_ground_color = aaag_generate_random_color_for("ground")
    draw_rectangle(aaag_canvas, 0, 0, aaag_scene_width,
                   aaag_ground_height, fill=aaag_ground_color)


def aaag_draw_clouds(aaag_canvas, aaag_scene_width, aaag_ground_level, aaag_scene_height):
    """This function generates cloud of different sizes in the provided canvas above the ground level in random places specified and before the limit of the width of the canvas"""
    aaag_rounded_ground_level = int(aaag_ground_level)
    aaag_amount_of_clouds = random.randint(3, 6)
    AAAG_SCALES = ["big", "medium", "small"]
    for aaag_index in range(aaag_amount_of_clouds):
        aaag_random_scale = AAAG_SCALES[random.randint(1, 2)]
        aaag_center_position_x = random.randint(10, aaag_scene_width)
        aaag_center_position_y = random.randint(aaag_rounded_ground_level + 100,
                                                aaag_scene_height)
        aaag_draw_cloud(aaag_canvas, aaag_random_scale,
                        aaag_center_position_x, aaag_center_position_y)


def aaag_draw_cloud(aaag_canvas, aaag_scale, aaag_center_position_x, aaag_center_position_y):
    """This function generates a cloud in the given position and of the given scale
    scale options: 
    big: Generates a big cloud
    medium: Generates a medium sized cloud 
    small: Generates an small cloud
    """

    aaag_ofset_x = 0
    aaag_ofset_y = 0
    aaag_center_x = aaag_center_position_x
    aaag_center_y = aaag_center_position_y
    for aaag_index in range(5):
        aaag_random_oval_witdh = random.randint(40, 100)
        aaag_random_oval_height = random.randint(30, 40)
        if aaag_scale == "big":
            aaag_random_oval_witdh += 50
            aaag_random_oval_height += 25
        elif aaag_scale == "medium":
            aaag_random_oval_witdh += 25
            aaag_random_oval_height += 15
        elif aaag_scale == "small":
            aaag_random_oval_witdh -= 10
            aaag_random_oval_height -= 10
        draw_oval(aaag_canvas, aaag_center_x - aaag_random_oval_witdh,
                  aaag_center_y - aaag_random_oval_height, aaag_center_x + aaag_random_oval_witdh, aaag_center_y + aaag_random_oval_height, outline=aaag_generate_random_color_for("cloud"), fill=aaag_generate_random_color_for("cloud"))

        if aaag_index == 1:
            aaag_ofset_x = -20
            aaag_ofset_y = -10
        elif aaag_index == 2:
            aaag_ofset_x = -35
            aaag_ofset_y = -15
        elif aaag_index == 3:
            aaag_ofset_x = 20
            aaag_ofset_y = 12
        elif aaag_index == 4:
            aaag_ofset_x = 35
            aaag_ofset_y = 19

        aaag_center_x += aaag_ofset_x
        aaag_center_y += aaag_ofset_y


def aaag_draw_trees(aaag_canvas, aaag_ground_level):
    """This function draws trees in a loop, the color of the trees is generated randomly and the size of the tree is also random from three options (tall, medium, small)"""
    aaag_rounded_ground_level = int(aaag_ground_level)
    aaag_amount_of_trees = random.randint(5, 10)
    AAAG_SCALES = ["big", "medium", "small"]
    aaag_tree_position_x = random.randint(100, 150)
    for aaag_index in range(aaag_amount_of_trees):
        aaag_random_scale = AAAG_SCALES[random.randint(0, 2)]
        aaag_tree_position_y = aaag_rounded_ground_level + \
            random.randint(-50, 80)
        aaag_draw_tree(aaag_canvas, aaag_random_scale,
                       aaag_tree_position_x, aaag_tree_position_y)
        aaag_tree_position_x = aaag_tree_position_x + random.randint(100, 200)


def aaag_draw_tree(aaag_canvas, aaag_scale, aaag_center_position_x, aaag_center_position_y):
    """This function draws a tree with the scale provided on the position marked for the center. The color is generated randomely"""

    if aaag_scale == "big":
        aaag_trunk_width = aaag_center_position_x - 60
        aaag_trunk_height = aaag_center_position_y - 120

        aaag_triangle_lower_left_point_x = aaag_center_position_x - 120
        aaag_triangle_lower_right_point_x = aaag_center_position_x + 60
        aaag_triangle_upper_point_y = aaag_center_position_y + 250
        aaag_triangle_upper_point_x = aaag_center_position_x - 30
    elif aaag_scale == "medium":
        aaag_trunk_width = aaag_center_position_x - 40
        aaag_trunk_height = aaag_center_position_y - 100

        aaag_triangle_lower_left_point_x = aaag_center_position_x - 80
        aaag_triangle_lower_right_point_x = aaag_center_position_x + 40
        aaag_triangle_upper_point_y = aaag_center_position_y + 210
        aaag_triangle_upper_point_x = aaag_center_position_x - 20
    else:
        aaag_trunk_width = aaag_center_position_x - 20
        aaag_trunk_height = aaag_center_position_y - 80

        aaag_triangle_lower_left_point_x = aaag_center_position_x - 40
        aaag_triangle_lower_right_point_x = aaag_center_position_x + 20
        aaag_triangle_upper_point_y = aaag_center_position_y + 180
        aaag_triangle_upper_point_x = aaag_center_position_x - 10

    draw_rectangle(aaag_canvas, aaag_center_position_x,
                   aaag_center_position_y, aaag_trunk_width, aaag_trunk_height, outline=aaag_generate_random_color_for("tree"), fill=aaag_generate_random_color_for("tree"))
    aaag_leaf_color = aaag_generate_random_color_for("leaf")
    draw_polygon(aaag_canvas, aaag_triangle_lower_left_point_x, aaag_center_position_y,
                 aaag_triangle_lower_right_point_x, aaag_center_position_y, aaag_triangle_upper_point_x, aaag_triangle_upper_point_y, outline=aaag_leaf_color, fill=aaag_leaf_color)


def aaag_generate_random_color_for(aaag_object):
    """This function returns a test color from the python color constants that matches the name of the object provided in the argument, if not provided it returns a random color from a default list. 
    4 possible colors per option are possible
    aaag_object options:
    sky: Generates colors related to sky
    ground: Generates colors related to ground
    """
    AAAG_COLORS = ["yellow1", "violetred", "darkolivegreen", "cadmiumyellow"]
    AAAG_COLORS_SKY = ["darkslategray2", "indianred1", "gray10", "royalblue2"]
    AAAG_COLORS_GROUND = ["green1",
                          "khaki2", "sienna3", "sienna"]
    AAAG_COLORS_CLOUDS = ["beige", "cornsilk1", "white", "gray91"]
    AAAG_COLORS_TREES = ["tan4", "chocolate", "darkorange4", "sienna3"]
    AAAG_COLORS_TREES_LEAFS = ["springgreen3",
                               "orangered1", "olivedrab", "darkolivegreen"]
    aaag_rand_int = random.randint(0, 3)

    if aaag_object == "sky":
        return AAAG_COLORS_SKY[aaag_rand_int]
    elif aaag_object == "ground":
        return AAAG_COLORS_GROUND[aaag_rand_int]
    elif aaag_object == "cloud":
        return AAAG_COLORS_CLOUDS[aaag_rand_int]
    elif aaag_object == "tree":
        return AAAG_COLORS_TREES[aaag_rand_int]
    elif aaag_object == "leaf":
        return AAAG_COLORS_TREES_LEAFS[aaag_rand_int]

    return AAAG_COLORS[aaag_rand_int]


if __name__ == "__main__":
    main()
