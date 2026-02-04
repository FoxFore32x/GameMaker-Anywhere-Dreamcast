if (gamepad_button_check(4, gp_face1)) {
    y += 5;
}

if (gamepad_button_check(4, gp_face4)) {
    y -= 5;
}

if (gamepad_button_check(4, gp_face2)) {
    x += 5;
}

if gamepad_button_check(4, gp_face3) {
    x -= 5;
}

if (gamepad_button_check_pressed(4, gp_select)) {
    x = 300;
	y = 400;
}

if (gamepad_button_check_released(4, gp_select)) {
    y = 300;
}

room_goto(Room2);