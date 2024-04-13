import numpy as np
import cv2

def my_float2int(img):
    
    # Don't use *255 twice
    # img = np.round(img * 255, 0)
    img = np.round(img, 0)
    img = np.minimum(img, 255)
    img = np.maximum(img, 0)
    img = img.astype('uint8')
    
    return img

def equalizeHistogram(img):
    
    img_height = img.shape[0]
    img_width = img.shape[1]
    histogram = np.zeros([256], np.int32) 
    
    
    # calculate histogram 
    for i in range(0, img_height):
        for j in range(0, img_width):
            histogram[img[i, j]] +=1
            
    # calculate pdf of the image
    pdf_img = histogram / histogram.sum()
    
    ### calculate cdf 
    # cdf initialize . 
    # Why does the type np.int32?
    #cdf = np.zeros([256], np.int32)
    cdf = np.zeros([256], float)

    # For loop for cdf
    for i in range(0, 256):
        for j in range(0, i+1):
            cdf[i] += pdf_img[j]

    # You may implement the "accumulated sum" in a more efficient way:
    cdf = np.zeros(256, float)
    cdf[0] = pdf_img[0]
    for i in range(1, 256):
        cdf[i] = cdf[i-1] + pdf_img[i]
     
    cdf_eq = np.round(cdf * 255, 0) # mapping, transformation function T(x)
    
    imgEqualized = np.zeros((img_height, img_width))
    
    # for mapping input image to s.
    for i in range(0, img_height):
        for j in range(0, img_width):
            r = img[i, j] # feeding intensity levels of pixels into r. 
            s = cdf_eq[r] # finding value of s by finding r'th position in the cdf_eq list.
            imgEqualized[i, j] = s # mapping s thus creating new output image.
            
    # calculate histogram equalized image here
    # imgEqualized = s # change this
    
    return imgEqualized

# end of function


# Read input image as Grayscale
img_low = cv2.imread('img_low.png', cv2.IMREAD_GRAYSCALE)

# 2.2 obtain the histogram equalized images using the above function
img_eq_low = equalizeHistogram(img_low)
img_eq_low = my_float2int(img_eq_low)

# Use cv2.imshow (instead of plt.imshow) just for testing.
cv2.imshow('img_eq_low', img_eq_low)
cv2.waitKey()