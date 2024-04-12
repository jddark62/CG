import cv2

def enhance_image(image_path):
    # Load the image
    image = cv2.imread(image_path)

    # Apply the filters
    enhanced_image = cv2.GaussianBlur(image, (5, 5), 0)
    enhanced_image = cv2.medianBlur(enhanced_image, 5)
    enhanced_image = cv2.bilateralFilter(enhanced_image, 9, 75, 75)

    # Display the original and enhanced images
    cv2.imshow("Original Image", image)
    cv2.imshow("Enhanced Image", enhanced_image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

# Path to the image
image_path = "/path/to/your/image.jpg"

# Call the function to enhance the image
enhance_image(image_path)