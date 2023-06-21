#include <stdio.h>

typedef struct {
    float length;
    float width;
    float height;
} Box;

float calculate_volume(Box* box) {
    return box->length * box->width * box->height;
}

float calculate_surface_area(Box* box) {
    return 2 * (box->length * box->width + box->width * box->height + box->height * box->length);
}

int main() {
    Box box;
    box.length = 2.5;
    box.width = 3.2;
    box.height = 1.8;

    // Accessing members using (*) asterisk or indirection operator and (.) dot operator
    Box* box_ptr = &box;
    float volume = (*box_ptr).length * (*box_ptr).width * (*box_ptr).height;
    float surface_area = 2 * ((*box_ptr).length * (*box_ptr).width + (*box_ptr).width * (*box_ptr).height + (*box_ptr).height * (*box_ptr).length);

    // Accessing members using (->) arrow operator
    float volume_ptr = box_ptr->length * box_ptr->width * box_ptr->height;
    float surface_area_ptr = 2 * (box_ptr->length * box_ptr->width + box_ptr->width * box_ptr->height + box_ptr->height * box_ptr->length);

    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surface_area);
    printf("Volume (using pointer): %.2f\n", volume_ptr);
    printf("Surface Area (using pointer): %.2f\n", surface_area_ptr);

    return 0;
}
