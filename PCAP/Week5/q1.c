#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

#define MAX_SOURCE_SIZE (0x100000)

int main() {
    // Declare variables
    int n = 10; // Number of integers to convert
    int *input_array, *output_array;
    char *source_str;
    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_uint num_devices, num_platforms;
    cl_int ret;
    cl_context context;
    cl_command_queue command_queue;
    cl_program program;
    cl_kernel kernel;
    cl_mem input_buffer, output_buffer;
    size_t global_size, local_size;
    size_t i;

    // Allocate memory for input and output arrays
    input_array = (int*)malloc(n * sizeof(int));
    output_array = (int*)malloc(n * sizeof(int));

    // Initialize input array with random integers
    for (i = 0; i < n; i++) {
        input_array[i] = i+10;
    }

    // Load the kernel source code
    FILE *fp;
    fp = fopen("octal.cl", "r");
    if (!fp) {
        fprintf(stderr, "Failed to load kernel.\n");
        exit(1);
    }
    source_str = (char*)malloc(MAX_SOURCE_SIZE);
    fread(source_str, 1, MAX_SOURCE_SIZE, fp);
    fclose(fp);

    // Get platform and device information
    ret = clGetPlatformIDs(1, &platform_id, &num_platforms);
    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &num_devices);

    // Create OpenCL context
    context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

    // Create command queue
    command_queue = clCreateCommandQueue(context, device_id, 0, &ret);

    // Create memory buffers
    input_buffer = clCreateBuffer(context, CL_MEM_READ_ONLY, n * sizeof(int), NULL, &ret);
    output_buffer = clCreateBuffer(context, CL_MEM_WRITE_ONLY, n * sizeof(int), NULL, &ret);

    // Copy data to memory buffers
    ret = clEnqueueWriteBuffer(command_queue, input_buffer, CL_TRUE, 0, n * sizeof(int), input_array, 0, NULL, NULL);

    // Create kernel program from source code
    program = clCreateProgramWithSource(context, 1, (const char**)&source_str, NULL, &ret);

    // Build kernel program
    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

    // Create Open

kernel = clCreateKernel(program, "convert_to_octal", &ret);


    // Set kernel arguments
ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&input_buffer);
ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&output_buffer);
ret = clSetKernelArg(kernel, 2, sizeof(int), (void*)&n);

// Define work-item and work-group size
global_size = n;
local_size = 1;

// Execute kernel
ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_size, &local_size, 0, NULL, NULL);

// Read output buffer and store result in output array
ret = clEnqueueReadBuffer(command_queue, output_buffer, CL_TRUE, 0, n * sizeof(int), output_array, 0, NULL, NULL);

// Display input and output arrays
printf("Input array: ");
for (i = 0; i < n; i++) {
    printf("%d ", input_array[i]);
}
printf("\n");

printf("Output array: ");
for (i = 0; i < n; i++) {
    printf("%d ", output_array[i]);
}
printf("\n");

// Clean up
ret = clFlush(command_queue);
ret = clFinish(command_queue);
ret = clReleaseKernel(kernel);
ret = clReleaseProgram(program);
ret = clReleaseMemObject(input_buffer);
ret = clReleaseMemObject(output_buffer);
ret = clReleaseCommandQueue(command_queue);
ret = clReleaseContext(context);
free(input_array);
free(output_array);
free(source_str);

return 0;
}
