# Task 1 — Investigation of Endianness

## Introduction
The concept of `endianness` refers to the order in which the byte of a multi-byte value are stored in computer memory. This becomes significant when a value such as a 16-bit, 32-bit or 64-bit integer occupies more than one byte.

Let us consider 32-bit hexadecimal value: `0x23456789`
Each hexadecimal digit represents 4 bits. therefore, eight hexadecimal digits represent: 8 × 4 = 32 bits

Since a byte consists of 8 bits, this value is composed of four bytes: `0x23`, `0x45`, `0x67`, and `0x89`

The byte `0x23` is considered the **Most Significant Byte (MSB)** because it contain the highest order bit of the number. These bits carry greatest positional weight and consequently, have the most significant impact on the overall numerical value. Conversely, the byte `0x89` is considered the **Least Significant Byte (LSB)** because it contains the lowest order bit and carries the least positional weight. This can be illustrated like:
`0x23` → Most significant byte
`0x89` → Least significant byte

There are two main approaches regarding byte order: **big endian** and **little endian**. They difer in which byte is placed at the lowest memory address.

## Little-Endian and Big-Endian
In the **big endian** system, **Most Significant Byte (MSB)** is stored at the lowest memory addres. For example, if the value `0x23456789` is at memory address `100`, it is stored like:

| Memory Address | Stored Byte |
|---|--|
| 100 | `0x23` |
| 101 | `0x45` |
| 102 | `0x67` |
| 103 | `0x89` |

In the **little endian** system, the **Least Significant Byte (LSB)** is stored at the lowest memory address. The same value is stored like:

| Memory Address | Stored Byte |
|---|---|
| 100 | `0x89` |
| 101 | `0x67` |
| 102 | `0x45` |
| 103 | `0x23` |

## Why Endianness Matters
`Endianness` is important when multi-byte data is transmitted or stored in memory or analyzed by various systems. If two systems use different byte orders and this difference is not accounted properly for then the same sequence of bytes may be interpreted as different numerical value. This issue is particularly critical in the field of `network comunication`, `binary file formats` and `serialization` (GeeksforGeeks, 2024).

## Critical Discussion
Neither `big endian` nor `little endian` can be considered universally superior since both represent corectly  the same numerical values. The `big endian` format is easier to read when inspecting memory since the most significant byte comes first aligning with the left to right sequence in which hexadecimal numbers are typically written. The main issue is not which byte order is used but whether different systems agree on the same format or not. Problem occur when data is exchanged without handling correctly the byte order.

## Conclusion
`Endianness` determines how the bytes of a multi-byte value are arranged in memory. In the `big endian` approach, MSB is stored at the lowest memory address, whereas in the `little endian` approach, LSB is stored at the lowest memory address. Although both approaches represent correctly the same values, understanding byte order is important when working with binary data and communication between different systems.

## References
GeeksforGeeks. (2024, May 23). What is endianness? Big-endian & little-endian. https://www.geeksforgeeks.org/dsa/little-and-big-endian-mystery/ 

MDN contributors. (2025, July 11). Endianness. MDN Web Docs. https://developer.mozilla.org/en-US/docs/Glossary/Endianness