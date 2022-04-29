
# CAN-NM Frame Generator

A program that generates a simple CAN NetworkManagement frame based on the available Partial Network Clusters (PNCs)

Tested for CAN and CanFD frames.


## Environment Variables

To build and run this project, you will need to add a compiler like `gcc` to your environment variables.
## Run Locally

Clone the project

```bash
  git clone https://github.com/youssefzaki28/NM-Frame-Generator
```

Go to the project directory

```bash
  cd NM-Frame-Generator
```

Build the source file, used MinGW's `gcc` as the compiler

```bash
  gcc NM_Generator.c -o NM_Gen
```

Start the program

```bash
  ./NM_Gen
```


## References


- [AUTOSAR System Template](https://www.autosar.org/fileadmin/user_upload/standards/classic/4-1/AUTOSAR_TPS_SystemTemplate.pdf)
- [Specification of the AUTOSAR Network Management Protocol](https://www.autosar.org/fileadmin/user_upload/standards/foundation/19-11/AUTOSAR_PRS_NetworkManagementProtocol.pdf)



## Feedback or Support

If you have any feedback or need support, please reach out to me at youssefzaki28@gmail.com

