import argparse
import hashlib
import struct
import unittest


class SHA1Hash:
    """
    Class to implement SHA1 Hashing Algorithm
    """

    def __init__(self, data):
        """
        Initializing the variables h and data. h is a list of five 8-digit hexadecimal numbers. 
        We will start with this as a message digest. 0x is how you write hexadecimal numbers in Python.
        """
        self.data = data
        self.h = [0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0]

    @staticmethod
    def rotate(n, b):
        """
        Static method to be used inside other methods. Left rotates n by b.
        """
        return ((n << b) | (n >> (32 - b))) & 0xFFFFFFFF

    def padding(self):
        """
        Pads the input message with zeros so that padded_data has 64 bytes or 512 bits
        """
        padding = b"\x80" + b"\x00" * (63 - (len(self.data) + 8) % 64)
        padded_data = self.data + padding + struct.pack(">Q", 8 * len(self.data))
        return padded_data

    def split_blocks(self):
        """
        Returns a list of bytestrings each of length 64
        """
        return [self.padded_data[i : i + 64] for i in range(0, len(self.padded_data), 64)]

    # @staticmethod
    def expand_block(self, block):
        """
        Takes a bytestring-block of length 64, unpacks it to a list of integers and
        returns a list of 80 integers after some bit operations
        """
        w = list(struct.unpack(">16L", block)) + [0] * 64
        for i in range(16, 80):
            w[i] = self.rotate((w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16]), 1)
        return w

    def final_hash(self):
        """
        This function does all the following operations using already defined utility functions:
        
        1. Pads the data.
        2. Splits into blocks and then does a series of operations for each block (including
        expansion).
        3. For each block, the variable h that was initialized is copied to a,b,c,d,e and 
        these 5 variables a,b,c,d,e undergo several changes. 
        4. After all the blocks are processed, these 5 variables are pairwise added to h i.e. 
        a to h[0], b to h[1] and so on.  
        
        ** This h becomes our final hash which is returned.
        """
        
        self.padded_data = self.padding()
        self.blocks = self.split_blocks()
        for block in self.blocks:
            expanded_block = self.expand_block(block)
            a, b, c, d, e = self.h
            for i in range(0, 80):
                if 0 <= i < 20:
                    f = (b & c) | ((~b) & d)
                    k = 0x5A827999
                elif 20 <= i < 40:
                    f = b ^ c ^ d
                    k = 0x6ED9EBA1
                elif 40 <= i < 60:
                    f = (b & c) | (b & d) | (c & d)
                    k = 0x8F1BBCDC
                elif 60 <= i < 80:
                    f = b ^ c ^ d
                    k = 0xCA62C1D6
                a, b, c, d, e = (
                    self.rotate(a, 5) + f + e + k + expanded_block[i] & 0xFFFFFFFF,
                    a,
                    self.rotate(b, 30),
                    c,
                    d,
                )
        self.h = (
            self.h[0] + a & 0xFFFFFFFF,
            self.h[1] + b & 0xFFFFFFFF,
            self.h[2] + c & 0xFFFFFFFF,
            self.h[3] + d & 0xFFFFFFFF,
            self.h[4] + e & 0xFFFFFFFF,
        )
        return "%08x%08x%08x%08x%08x" % tuple(self.h)


class SHA1HashTest(unittest.TestCase):
    """
    Test class for the SHA1Hash class. Inherits the TestCase class from unittest
    """

    def testMatchHashes(self):
        msg = bytes("This is some test text.", "utf-8")
        self.assertEqual(SHA1Hash(msg).final_hash(), hashlib.sha1(msg).hexdigest())


def main():
    
    #unittest.main()
    parser = argparse.ArgumentParser(description="Generate SHA1 hash")
    parser.add_argument(
        "--string","-s",
        dest="input_string",
        default="Hello World!! Just be secure.",
        type=str,
        help="String for which the hash is to be generated",
    )
    parser.add_argument(
        "--input-file","-i",
        dest="input_file", 
        help="Hash contents of a file"
    )
    parser.add_argument(
        "--output-file","-o",
        dest="output_file",
        help="Save the hash to a file"
    )
    
    args = parser.parse_args()
    input_string = args.input_string
    
    # In any case hash input should be a bytestring
    if args.input_file:
        if not args.output_file:
            print("Please provide the path to the output file. Use option --output-file or -o")
            exit(0)
        with open(args.input_file, "rb") as f, open(args.output_file,"w") as g:
            hash_input = f.read()
            sha1 = SHA1Hash(hash_input).final_hash()
            g.write(sha1)
            print(f"SHA1 hash successfully generated and saved in {args.output_file}")
            print(f"\nGenerated SHA1 hash : {sha1}")
    else:
        hash_input = bytes(input_string, "utf-8")
        print(f"\nGenerated SHA1 hash : {SHA1Hash(hash_input).final_hash()}")


if __name__ == "__main__":
    main()