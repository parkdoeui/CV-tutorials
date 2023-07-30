#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

void print_image_data(image im) {
    for (int c = 0; c < im.c; c++) {
        printf("Channel %d:\n", c + 1);
        for (int y = 0; y < im.h; y++) {
            for (int x = 0; x < im.w; x++) {
                int index = c * im.w * im.h + y * im.w + x;
                printf("%.2f ", im.data[index]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int get_index(int w, int h, int x, int y, int c) {
    return c * w * h + y * w + x;
}

float get_pixel(image im, int x, int y, int c)
{
    if(x > im.w || y > im.h || c > im.c || x < 0 || y < 0 || c < 0){
        printf("Pixel out of bounds\n");
        return 0;
    }

    // check if im has data property
    if (!im.data) {
        fprintf(stderr, "Image does not have data property\n");
        return 0;
    }

    // or return the data property
    int index = get_index(im.w, im.h, x, y, c);
    return im.data[index];
}

void set_pixel(image im, int x, int y, int c, float v)
{   
    if((x > im.w || y > im.h || c > im.c || x < 0 || y < 0 || c < 0)){
        printf("Pixel out of bounds\n");
        return;
    }

    if(!im.data) {
        fprintf(stderr, "Image does not have data property\n");
        return;
    }
    int index = get_index(im.w, im.h, x, y, c); 
    im.data[index] = v;
    // TODO Fill this in
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    // TODO Fill this in
    // copy image data to copied image using memcpy
    memcpy(copy.data, im.data, im.w * im.h * im.c * sizeof(float));
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    
    for(int y = 0; y<im.h; y++) {
        for(int x = 0; x<im.w; x++) {
            int r_index = get_index(im.w, im.h, x, y, 0);
            int g_index = get_index(im.w, im.h, x, y, 1);
            int b_index = get_index(im.w, im.h, x, y, 2);
            gray.data[y * im.w + x] += im.data[r_index] * 0.299 + im.data[g_index] * 0.587 + im.data[b_index] * 0.114;
        }
    }
    
    // TODO Fill this in
    return gray;
}

void shift_image(image im, int c, float v)
{
    for( int x=0;x<im.w;x++) {
        for(int y=0;y<im.h;y++) {
            int index = get_index(im.w, im.h, x, y, c);
            im.data[index] += v;
        }
    }
    
    // TODO Fill this in
}

void clamp_image(image im)
{
    // TODO Fill this in
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
