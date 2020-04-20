//
//  imaging.c
//  
//
//  Created by Jack Michaletz on 4/5/20.
//

#include "imaging.h"
#include "kmain.h"

short bob[] = {
0xE7DC,
0xE7DC, 0xE7DC, 0xE7DC, 0x8EB1, 0x76DC, 0xE8B1, 0x8EB1, 0xE7DC,
0xE7DC, 0xE7DC, 0xE7DC, 0xE7DC, 0xE7DC, 0xE7DC, 0xE7DC, 0xE7DC,
0xE7DC, 0xE7DC, 0xE7DC, 0xE7DC, 0xE7DC, 0xE7DC, 0xE7DC, 0xE7DC,
0xE7DC, 0xE7DC, 0xE7DC, 0xE7DC, 0x8EB1, 0x8EB1, 0x76DC, 0xACB1,
0x8EB1, 0x8EB1, 0xE7DC, 0xE7DC, 0xE7DC, 0xE7DC, 0x8EB1, 0x8EB1,
0x8EB1, 0x8EB1, 0x8EB1, 0x8EB1, 0x8EB1, 0x8EB1, 0x8EB1, 0x8EB1,
0x8EB1, 0x8EB1, 0x8EB1, 0x8EB1, 0x8EB1, 0x8EB1, 0xEB1, 0x8EB1,
0x8EB1, 0x8EB1, 0x8EB1, 0x8EB1, 0x8EB1, 0x8EB1, 0x8EB1, 0x8EB1,
0xE0B0, 0x8EB1, 0x8EB1, 0xE0B0, 0xE0B0, 0x7EDC, 0x7EDC, 0xE0B0,
0xE0B0, 0xE0B0, 0xE7DC, 0x8EB1, 0xACB1, 0x76DC, 0x8EB1, 0x5EB1,
0x5EB1, 0x5EB1, 0x5EB1, 0x72B0, 0x6FB1, 0xC7B1, 0x7CB0, 0xF6B1,
0x5EB1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1,
0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0x67DC, 0x7CB0, 0xF6B1, 0x5EB1,
0x1EB1, 0x5EB1, 0x5EB1, 0x67DC, 0x5EB1, 0xE7B1, 0x1EB1, 0x67DC,
0x87DC, 0x67DC, 0x87DC, 0x87DC, 0x87DC, 0x67DC, 0x87DC, 0x87DC,
0x87DC, 0x87DC, 0x67DC, 0x67DC, 0x67DC, 0x67DC, 0x87DC, 0x67DC,
0x67DC, 0x67DC, 0x67DC, 0x67DC, 0x67DC, 0x5EB1, 0x87DC, 0x67DC,
0x67DC, 0x67DC, 0x67DC, 0x67DC, 0x67DC, 0x67DC, 0x67DC, 0x67DC,
0x67DC, 0x67DC, 0x67DC, 0x67DC, 0x67DC, 0x67DC, 0x67DC, 0x67DC,
0x67DC, 0x67DC, 0xF6B1, 0xF6B1, 0x67B1, 0x87DC, 0x67DC, 0x5EB1,
0x5EB1, 0x5EB1, 0x5EB1, 0x5EB1, 0x6FB1, 0xE7B1, 0x6FB1, 0x5EB1,
0x4FB1, 0xC7B1, 0xC7B1, 0xC7B1, 0xC7B1, 0xC7B1, 0xC7B1, 0xC7B1,
0xC7B1, 0xC7B1, 0xC7B1, 0xC7B1, 0xC7B1, 0xC7B1, 0xC7B1, 0xC7B1,
0xC7B1, 0x5EB1, 0xF6B1, 0xF6B1, 0x5EB1, 0x6FB1, 0x5EB1, 0xC7B1,
0xC7B1, 0xF6B1, 0x67B1, 0x67B1, 0x67B1, 0x67B1, 0xF6B1, 0xF6B1,
0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1,
0x67B1, 0xF6B1, 0xF6B1, 0xF6B1, 0x4FB1, 0x4FB1, 0xF6B1, 0xC7B1,
0xC7B1, 0xC7B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1,
0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1,
0xF6B1, 0xF6B1, 0x5EB1, 0x6FB1, 0xF6B1, 0xBCB1, 0xF6B1, 0x5EB1,
0x5EB1, 0x5EB1, 0x5EB1, 0xF6B1, 0xC7B1, 0x76B0, 0x76B0, 0x5EB1,
0x4FB1, 0x4FB1, 0xC7B1, 0x76B0, 0x76B0, 0x76B0, 0xC7B1, 0xC7B1,
0xC7B1, 0xC7B1, 0xC7B1, 0xC7B1, 0xC7B1, 0xC7B1, 0xBCB1, 0x67B1,
0x78DC, 0x67B1, 0x67B1, 0x67B1, 0x78DC, 0x78DC, 0x78DC, 0x78DC,
0x78DC, 0x78DC, 0x80DC, 0x80DC, 0x80DC, 0x82B0, 0x86B0, 0x78DC,
0x78DC, 0x78DC, 0x78DC, 0x78DC, 0x78DC, 0x67B1, 0x67B1, 0xF6B1,
0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0x5EB1, 0x76B0, 0xBCB1, 0x5EB1,
0x74B0, 0xC7B1, 0xC7B1, 0xC7B1, 0xC7B1, 0xF6B1, 0xF6B1, 0xF6B1,
0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1,
0xF6B1, 0xF6B1, 0x5EB1, 0x5EB1, 0x67B1, 0x67B1, 0x3CB1, 0xC7B1,
0xC7B1, 0xC7B1, 0xC7B1, 0xC7B1, 0x67B1, 0x67B1, 0x78DC, 0x7CB0,
0x76B0, 0xC7B1, 0xC7B1, 0xC7B1, 0xBCB1, 0xF6B1, 0xF6B1, 0xF6B1,
0xF6B1, 0xC7B1, 0x7CDC, 0x76DC, 0x86DC, 0x86DC, 0x86DC, 0x86DC,
0x86DC, 0x86DC, 0x86DC, 0x86DC, 0x86DC, 0x86DC, 0x86DC, 0x46DC,
0x46DC, 0x46DC, 0x46DC, 0x46DC, 0x46DC, 0x86DC, 0x86DC, 0x86DC,
0x86DC, 0x86DC, 0x86DC, 0x86DC, 0x6DC, 0x6DC, 0x6DC, 0x86DC,
0x86DC, 0x86DC, 0x61B0, 0x68B1, 0x68B1, 0x78DC, 0x78DC, 0x78DC,
0x78DC, 0x78DC, 0x67B1, 0x67B1, 0xBCB1, 0x7CB0, 0xBCB1, 0xF6B1,
0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1, 0xF6B1,
0xF6B1, 0xBCB1, 0x7CB0, 0x7CB0, 0x78DC, 0x78DC, 0x47B1, 0x6EDC,
0x7EDC, 0x7EDC, 0x7EDC, 0x7EDC, 0x7EDC, 0x7EDC, 0x7EDC, 0x6EDC,
0x6EDC, 0x6EDC, 0x6EDC, 0x6CDC, 0x76B1, 0x69B0, 0xCB1, 0x47B0,
0x47B0, 0x65B0, 0x4FB0, 0x4FB0, 0x4FB0, 0x4FB0, 0xC0B0, 0xC0B0,
0xC0B0, 0xC0B0, 0xC0B0, 0xC0B0, 0xC0B0, 0x6CDC, 0x6CDC, 0x6CDC,
0x6CDC, 0x6CDC, 0x4CB1, 0x6CDC, 0x6CDC, 0x6CDC, 0x6CDC, 0x6CDC,
0x6CDC, 0x4CB1, 0x4CB1, 0x6CB1, 0x4CB1, 0x6CDC, 0x6CB1, 0x6CB1,
0x6CB1, 0x4CB1, 0x6CB1, 0x6CDC, 0x6CDC, 0x6CDC, 0x6CDC, 0x6CDC,
0x6CDC, 0x8CDC, 0x86DC, 0x86DC, 0x86DC, 0x86DC, 0x63B0, 0x76DC,
0x7EDC, 0x7EDC, 0x7EDC, 0x7EDC, 0x7EDC, 0x7EDC, 0x7EDC, 0x7EDC,
0x7EDC, 0x7EDC, 0x7EDC, 0x7EDC, 0x7EDC, 0x67B1, 0x86DC, 0xE8B0,
0xE8B0, 0xE8B0, 0xE8B0, 0xE8B0, 0xE8B0, 0x9EB2, 0xE7DC, 0xE6DC,
0x76DC, 0x56B2, 0x4AB0, 0x4AB0, 0x46B1, 0x47B0, 0x47B0, 0x4EB0,
0x65B0, 0x4FB0, 0xC0B0, 0xC0B0, 0xC0B0, 0xC0B0, 0xC0B0, 0xC0B0,
0xC0B0, 0xC0B0, 0xC0B0, 0xC0B0, 0x6CDC, 0x4CB1, 0x4CB1, 0x4CB1,
0x4CB1, 0x4CB1, 0x6CB1, 0x6CB1, 0x6CB1, 0x6CB1, 0x6CB1, 0x6CB1,
0x6CB1, 0x6CB1, 0xCB2, 0xCB2, 0xCB2, 0xCB2, 0xCB2, 0xCB2,
0xCB2, 0xCB2, 0x6CB1, 0x6CB1, 0x6CB1, 0xCB2, 0x6CB1, 0x6CB1,
0x6CB1, 0x6CB1, 0x6CB1, 0x6CB1, 0x6CB1, 0x6CDC, 0x6CDC, 0x6CDC,
0x6CDC, 0xC6DC, 0x76DC, 0xE6DC, 0xECDC, 0x8EB1, 0xE7DC, 0xE7DC,
0xE6DC, 0xE6DC, 0xE7DC, 0x8EB1, 0x76DC, 0x67B1, 0x3CB1, 0xE8B0,
0xE8B0, 0xE8B0, 0xE4B0, 0xE8B0, 0xE6DC, 0x76DC, 0x4AB0, 0xCB1,
0xCB1, 0x4AB0, 0x4AB0, 0xCB1, 0x46B1, 0x47B0, 0x4EB0, 0x4EB0,
0x4FB0, 0x4FB0, 0x4EB0, 0x4FB0, 0x6DB0, 0x6DB0, 0xC6DC, 0xC3B0,
0x47B1, 0xC2B0, 0xC2B0, 0xC6DC, 0xC2B0, 0xC2B0, 0x6DB0, 0x6CB1,
0x6CB1, 0x6CB1, 0xCB2, 0xCB2, 0xCB2, 0xC6B0, 0xC6B0, 0xC6B0,
0xC6B0, 0x2CB2, 0x2CB2, 0x2CB2, 0x2CB2, 0x2CB2, 0x2CB2, 0x2CB2,
0x2CB2, 0x2CB2, 0x2CB2, 0x2CB2, 0x2CB2, 0x2CB2, 0x2CB2, 0x2CB2,
0xC6B0, 0xC6B0, 0xC6B0, 0xC4B0, 0xCB2, 0xCB2, 0x6CB1, 0x6CB1,
0x6CB1, 0x6CB1, 0x6CB1, 0x6CDC, 0x6CDC, 0x6DB0, 0xF6B2, 0x2CB1,
0x2CB1, 0xEB1, 0x76B1, 0x67DC, 0x76B1, 0x76B1, 0x3CB1, 0xE8B0,
0xE1B0, 0xE1B0, 0xECDC, 0x86B1, 0x4AB0, 0x43B0, 0x43B0, 0xCB1,
0xCB1, 0x4AB0, 0x4AB0, 0x46B1, 0x46B1, 0x47B0, 0x47B0, 0x4EB0,
0x4FB0, 0x65B0, 0x68DC, 0x67DC, 0xC7B2, 0x7FDC, 0x6FB2, 0x6FB2,
0x6FB2, 0x7FB2, 0x7FB2, 0x6FB2, 0x7FDC, 0x7FDC, 0xCFDC, 0x6FDC,
0xC7DC, 0xC6DC, 0xC6DC, 0x6CB1, 0x6CB1, 0x2CB2, 0x2CB2, 0x2CB2,
0xC6DC, 0xC6DC, 0xC6DC, 0xC6DC, 0xC6DC, 0xC7DC, 0xC7DC, 0xC7DC,
0xC7DC, 0xC7DC, 0xC7DC, 0xC7DC, 0xC7DC, 0xC8DC, 0xC6DC, 0xC6DC,
0xC2B0, 0xACB2, 0xACB2, 0xACB2, 0x2CB2, 0x2CB2, 0xC6B0, 0xC6B0,
0xCB2, 0xCB2, 0x6CB1, 0x6CB1, 0x4CB1, 0xC0B0, 0x4CB1, 0xC0B0,
0x6CB0, 0x67B0, 0x76B1, 0x76DC, 0x76B1, 0x86DC, 0x3CB1, 0xE8B0,
0x1EB2, 0x76DC, 0x64DC, 0x43B0, 0x84B1, 0x84B1, 0x43B0, 0x43B0,
0xCB1, 0xCB1, 0x4AB0, 0x46B1, 0x4AB0, 0x65B0, 0x47B0, 0x47B0,
0xCB1, 0x68DC, 0x1EB1, 0xE7B2, 0x7FB0, 0xF7DC, 0xFB2, 0xEFB2,
0x2FB2, 0xF8DC, 0x70DC, 0x70DC, 0x70DC, 0xF8DC, 0xF7DC, 0x7FB2,
0x7FB2, 0x7FB2, 0x7FDC, 0x6FDC, 0x67DC, 0x68DC, 0x68DC, 0x67DC,
0x87DC, 0x7FDC, 0x7FDC, 0x4FB2, 0x6FB2, 0x7FB2, 0xF7DC, 0xF7DC,
0xF7DC, 0xF7DC, 0xF7DC, 0x7FB2, 0x7FB2, 0x7FB2, 0x6FB2, 0x7FDC,
0x67DC, 0x69B0, 0xC6DC, 0x7CB1, 0xBCB2, 0x7CB2, 0xACB2, 0x2CB2,
0x2CB2, 0x6CB1, 0x6CB1, 0x6CB1, 0x6CB1, 0x6CB1, 0x6CB1, 0x6CDC,
0xC0B0, 0xC0B0, 0x65B0, 0xD6B2, 0x76B1, 0x2CB1, 0x3CB1, 0x1EB2,
0xE7DC, 0x60B0, 0xC0B1, 0xC0B1, 0x84B1, 0x64DC, 0x84B1, 0x64DC,
0x43B0, 0x43B0, 0xCB1, 0xCB1, 0x4AB0, 0x4AB0, 0xCB1, 0x43B0,
0x65B0, 0x47B1, 0x76B0, 0x7B2, 0x67B2, 0x7FB0, 0xF7DC, 0x6FB2,
0x7FDC, 0x7DC, 0xF0B2, 0x80B2, 0x20, 0x80B2, 0xF0B2, 0x87DC,
0x2FB2, 0xEFB2, 0x7FB2, 0x7FB2, 0x6FB2, 0x7FB0, 0x67B2, 0x9EB1,
0x7FB0, 0x7FB1, 0x2FB2, 0xEFB2, 0x7FB2, 0x78DC, 0x70B2, 0x2B0,
0x2B0, 0x70B2, 0xB0B2, 0x8020, 0x6FB2, 0xEFB2, 0xEFB2, 0x7FB2,
0x4FB2, 0x7CB0, 0xCB1, 0xC3B0, 0xBCB2, 0xACB2, 0xACB2, 0xACB2,
0x2CB2, 0xCB2, 0x6CB1, 0x6CB1, 0x6CB1, 0x6CB1, 0x6CB1, 0xC0B0,
0xC0B0, 0xC0B0, 0xC0B0, 0x65B0, 0x4FB0, 0x74B1, 0x7CDC, 0xE5B0,
0xC6DC, 0x48B1, 0xC0B1, 0xC0B1, 0xC0B1, 0x84B1, 0x84B1, 0x46DC,
0x46DC, 0x67DC, 0x67DC, 0x67DC, 0x67DC, 0x67DC, 0xCB1, 0x43B0,
0xCB1, 0x8CB1, 0x7CDC, 0x7CB0, 0x1EB1, 0x70B0, 0x67B2, 0xE7B2,
0x7FB0, 0x7FB0, 0x7FB0, 0x7020, 0x7020, 0xF7B2, 0xF7DC, 0xF7DC,
0xF7DC, 0xF7DC, 0xF7DC, 0xF7DC, 0x7FB0, 0xE7B2, 0x7B2, 0x7B2,
0x67B2, 0x9EB1, 0xF7DC, 0xF7DC, 0xF7DC, 0x7FB0, 0x87DC, 0x7DC,
0x7DC, 0x7DC, 0x87DC, 0xF0B0, 0xF7DC, 0xF7DC, 0xF7DC, 0xF7DC,
0xF7DC, 0xC7B1, 0xC7B0, 0xACB2, 0x2CB2, 0x2CB2, 0xC6B0, 0xCB2,
0x6CB1, 0x6CB1, 0x6CB1, 0x4CB1, 0xC6DC, 0xC0B0, 0xC0B0, 0xC6DC,
0xC0B0, 0xC0B0, 0x65B0, 0x65B0, 0x4FB0, 0x4FB0, 0x74B1, 0x8EB1,
0xACB1, 0x48B1, 0x84B1, 0x46DC, 0x46DC, 0x67DC, 0xE7B2, 0xE7B1,
0x7EB0, 0x27B2, 0x6FB1, 0x7FB0, 0x6FB1, 0x4FB1, 0x7CDC, 0x61B0,
0x43B0, 0xCB1, 0x4BB0, 0xC6DC, 0x7CDC, 0x3CB1, 0x3CB1, 0x78DC,
0x78DC, 0x78DC, 0x7B2, 0x67B2, 0x7020, 0xE7B2, 0xE7B2, 0xE7B2,
0xE7B2, 0xE7B2, 0x4FB1, 0x5EB1, 0xC3B0, 0x6CDC, 0x7CDC, 0x7CDC,
0x7CDC, 0xC7B1, 0x7CDC, 0x7CDC, 0x7CDC, 0xC7B1, 0x7CB0, 0x4FB1,
0xE7B2, 0x9EB1, 0xE7B2, 0xE7B2, 0xE7B2, 0x67B2, 0x67B2, 0x76DC,
0x7CDC, 0xC3B0, 0x6CB1, 0xC6DC, 0xC6DC, 0xC6DC, 0xC6DC, 0xC6DC,
0xC6DC, 0xC2B0, 0x67DC, 0x67DC, 0xC7DC, 0xC7DC, 0x7CB0, 0x7CB0,
0xC7DC, 0x67DC, 0x6CDC, 0x4FB0, 0x47B0, 0x47B0, 0xCB1, 0xE1B0,
0x8EB1, 0x63B0, 0xCB1, 0xCB1, 0x4BB0, 0x76DC, 0x76DC, 0xC6DC,
0x76B1, 0xC6DC, 0x76DC, 0xC6DC, 0xC6DC, 0x69B0, 0x64DC, 0x64DC,
0x64DC, 0x84B1, 0x84B1, 0xCB1, 0xCB1, 0x69B0, 0x6CDC, 0x67DC,
0x7CB0, 0x7CB0, 0x4FB1, 0x67B2, 0x76B0, 0x7CDC, 0x7CDC, 0x3CB1,
0xC6DC, 0x74B1, 0x6DB0, 0x6CDC, 0x67B1, 0xC7DC, 0xCEDC, 0xC7DC,
0xCAB0, 0x6CDC, 0x6DB0, 0x67B0, 0xC6DC, 0xC6DC, 0xC6DC, 0xC6DC,
0x76DC, 0x76DC, 0x76DC, 0xF6B1, 0x76B0, 0xBCB1, 0x67B2, 0x7020,
0xC7DC, 0x67DC, 0xC0B0, 0xC0B0, 0xC0B0, 0xC0B0, 0xC0B0, 0xC7DC,
0x6FB1, 0x7FB0, 0x7FB0, 0x7020, 0xBCB1, 0xBCB1, 0x7CB0, 0x76B0,
0x76B0, 0x7CB0, 0x67B1, 0x65B0, 0x46B1, 0x4AB0, 0x43B0, 0xE7DC,
0xE7DC, 0xC7DC, 0x67DC, 0x56B1, 0x74B1, 0x67DC, 0xC7DC, 0x76B1,
0x69B0, 0x61B0, 0x61B0, 0x16B2, 0x69B0, 0x76B1, 0x67DC, 0x46DC,
0x84B1, 0x46DC, 0x67DC, 0x7020, 0x7FB0, 0x7FB0, 0xE7B2, 0x7CB0,
0x7CDC, 0xC6DC, 0x67B0, 0x69B0, 0x69B0, 0x69B0, 0x61B0, 0x16B2,
0x6CDC, 0xCAB0, 0xC7B0, 0xBCB2, 0x7CB1, 0x7CDC, 0x7CDC, 0x7CDC,
0x7CB1, 0xCAB0, 0x6DB0, 0x6DB0, 0x65B0, 0x4AB0, 0x4AB0, 0x4AB0,
0x4AB0, 0x16B2, 0x96B2, 0x67B0, 0x76DC, 0x76DC, 0x76DC, 0x76DC,
0x76DC, 0xBCB1, 0x27B2, 0x67DC, 0x67DC, 0x67DC, 0x67DC, 0xF6B1,
0x76DC, 0x76DC, 0x76DC, 0x76DC, 0x76DC, 0x76DC, 0x69B0, 0x68B1,
0x69B0, 0x2CB1, 0x67DC, 0x4AB0, 0x4AB0, 0x4AB0, 0x60B0, 0x7FB0,
0xF0B0, 0x7FB0, 0xF0B0, 0x7FB0, 0xC7B2, 0xE7B2, 0x27B2, 0x74B0,
0x67DC, 0x67DC, 0x69B0, 0xB6B2, 0x76B1, 0x76B1, 0x76B1, 0x76DC,
0x87DC, 0x37B2, 0x7FB0, 0x7CB0, 0xC7B1, 0xC7B1, 0x67B1, 0x76DC,
0xC6DC, 0x67B0, 0x69B0, 0x43B0, 0x69B0, 0xC8B1, 0x48B1, 0x68DC,
0x69B0, 0xC6DC, 0xC6DC, 0xC6DC, 0xC6DC, 0xC6DC, 0xC6DC, 0xC6DC,
0x6DB0, 0x6DB0, 0x74B1, 0x4BB0, 0xCB1, 0x4BB0, 0xCB1, 0xCB1,
0x46B1, 0x46B1, 0x56B2, 0x65B0, 0x96B2, 0x36B2, 0x76B1, 0x67B1,
0xC7B1, 0xC7DC, 0xC7DC, 0x7CDC, 0x7CDC, 0x76DC, 0x76B1, 0x69B0,
0x69B0, 0x69B0, 0x2CB1, 0x69B0, 0x63B0, 0x61B0, 0x69B0, 0x68DC,
0x68DC, 0x67B1, 0x76B0, 0x76B0, 0xF7B2, 0x7FB0, 0xF7B2, 0x7CDC,
0x5EB1, 0x6FB1, 0x6FB1, 0xE7B2, 0x7FB0, 0xF0B0, 0xF0B0, 0x7FB0,
0x67B2, 0x47B1, 0x76B1, 0x2CB1, 0x69B0, 0x69B0, 0x69B0, 0x76B1,
0x76B1, 0x47B1, 0xC7DC, 0x67B1, 0xC7B1, 0x67B1, 0x67DC, 0x67DC,
0x2CB1, 0x69B0, 0x64DC, 0x43B0, 0x64DC, 0x48B1, 0x48B1, 0x48B1,
0xC0B1, 0x68DC, 0x68DC, 0x68DC, 0x68DC, 0x68DC, 0x68DC, 0x68DC,
0x68DC, 0x68DC, 0x68DC, 0x64DC, 0x43B0, 0xCB1, 0xCB1, 0x4AB0,
0x4AB0, 0x4AB0, 0x4AB0, 0x4AB0, 0x4AB0, 0x65B0, 0x69B0, 0xC6DC,
0x76DC, 0x67B1, 0xC7DC, 0x76B1, 0x67B0, 0x36B2, 0x36B2, 0x61B0,
0x61B0, 0x86B1, 0x69B0, 0x67DC, 0x67DC, 0x67DC, 0x7CB0, 0x4FB1,
0x7020, 0x9EB1, 0xC7B2, 0xE7B2, 0xE7B2, 0x9EB1, 0x7CB0, 0xC7DC,
0x6FB0, 0xC6DC, 0x76DC, 0x76DC, 0x4FB1, 0x4FB1, 0x7CDC, 0x76DC,
0x76DC, 0x69B0, 0x68DC, 0x61B0, 0x61B0, 0x86B1, 0x68DC, 0x69B0,
0x69B0, 0xC8B1, 0x67DC, 0x67DC, 0x67B1, 0x76DC, 0x76DC, 0x64DC,
0x64DC, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0x84DC,
0x84DC, 0x84DC, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0x80DC, 0xC0B1,
0xC0B1, 0x46DC, 0x46DC, 0x43B0, 0xCB1, 0xCB1, 0xCB1, 0x43B0,
0xCB1, 0xCB1, 0xCB1, 0xCB1, 0xCB1, 0xCB1, 0xCB1, 0x6B2,
0x2CB1, 0x76B1, 0xC6DC, 0x76DC, 0x76B1, 0x76B1, 0xB6B2, 0x69B0,
0x69B0, 0x67B0, 0x4FB1, 0x6FB1, 0xF7B2, 0x7FB0, 0x7020, 0x74B0,
0xBCB1, 0x67B1, 0x76DC, 0x76DC, 0x78DC, 0x78DC, 0xE8B1, 0x7EB0,
0x67B1, 0x76DC, 0x76B1, 0xB6B2, 0x69B0, 0x69B0, 0x69B0, 0x69B0,
0x69B0, 0x61B0, 0x61B0, 0x86DC, 0x69B0, 0x76B1, 0x67DC, 0x67DC,
0x47B1, 0x67B1, 0x76DC, 0x76DC, 0x6BB0, 0x64DC, 0x64DC, 0xC0B1,
0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0x48DC, 0x80DC, 0x80DC,
0x80DC, 0x8DC, 0x8DC, 0x6DC, 0x6DC, 0x6DC, 0x6DC, 0x6DC,
0x6DC, 0x6DC, 0x8DC, 0x8DC, 0x60B1, 0x80DC, 0x80DC, 0x60DC,
0x64DC, 0x84B1, 0x64DC, 0x64DC, 0x84B1, 0x43B0, 0x43B0, 0x43B0,
0x43B0, 0x43B0, 0x61B0, 0x61B0, 0x68B1, 0x69B0, 0x69B0, 0x69B0,
0x36B2, 0x69B0, 0x67B0, 0xC6DC, 0xC6DC, 0x76DC, 0x76DC, 0x86DC,
0x86DC, 0x68B1, 0x68B1, 0x86DC, 0xC8B1, 0x78DC, 0x78DC, 0x7FB0,
0xF7B2, 0x67B2, 0x67DC, 0x67DC, 0x76B1, 0x76B1, 0x69B0, 0x69B0,
0x6BB0, 0x6BB0, 0x76B1, 0x76B1, 0x76B1, 0x76DC, 0x76DC, 0x76B1,
0x6BB0, 0x69B0, 0x61B0, 0x84DC, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1,
0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0x84DC, 0x84DC, 0x84DC,
0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0x43B0, 0x84B1,
0x84B1, 0x84B1, 0x84B1, 0x64DC, 0x64DC, 0x64DC, 0x64DC, 0x64DC,
0x64DC, 0x43B0, 0x43B0, 0x43B0, 0x43B0, 0x84B1, 0x84B1, 0x64DC,
0x64DC, 0x64DC, 0x84B1, 0x64DC, 0x64DC, 0x64DC, 0x48B1, 0x61B0,
0x61B0, 0x61B0, 0x69B0, 0x69B0, 0x69B0, 0x69B0, 0x68B1, 0x86DC,
0x86DC, 0x86DC, 0x69B0, 0x69B0, 0x6BB0, 0x67DC, 0x67DC, 0x4FB1,
0xE7B2, 0x7FB0, 0xF0B0, 0x7FB0, 0x6FB1, 0x67DC, 0x76B1, 0x76B1,
0x76B1, 0x76B1, 0x76B1, 0x76B1, 0x69B0, 0x69B0, 0x68DC, 0x68DC,
0x64DC, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1,
0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1,
0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1,
0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1,
0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1,
0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1,
0xC0B1, 0xC0B1, 0x68DC, 0x68DC, 0x68DC, 0x69B0, 0x69B0, 0x69B0,
0x69B0, 0x67DC, 0x67DC, 0xBCB1, 0x7CB0, 0x9EB1, 0xE7B2, 0xC6DC,
0x76DC, 0x7CDC, 0x76DC, 0xC6DC, 0xC6DC, 0x76B1, 0x76B1, 0x76B1,
0x76B1, 0x6BB0, 0x2CB1, 0x63B0, 0x63B0, 0xA4B1, 0x86DC, 0x86DC,
0x86DC, 0x86DC, 0x48DC, 0x46DC, 0x48DC, 0xC0B1, 0xC0B1, 0xC0B1,
0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1, 0xC0B1,
0xC0B1, 0x6B1, 0x60B1, 0x60B1, 0x60B1, 0x6B1, 0x6B1, 0x60B1,
0x60B1, 0x60B1, 0x6B1, 0x6B1, 0x6B1, 0x6B1, 0xC0B1, 0xC0B1,
0xC0B1, 0xC0B1, 0xC0B1, 0x48DC, 0xC0B1, 0xC0B1, 0xC0B1, 0x40DC,
0x40DC, 0xCB0, 0x40DC, 0x40DC, 0x40DC, 0x40DC, 0x80DC, 0x8DC,
0x6DC, 0x8EDC, 0x6EDC, 0x67DC, 0x67DC, 0xBCB1, 0x4FB1, 0x7CB0,
0x7CB0, 0x7CB0, 0x7CB0, 0xBCB1, 0x76B0, 0x76B0, 0x78DC, 0x2CB1,
0x61B0, 0x69B0, 0x69B0, 0x69B0, 0xB6B2, 0x76DC, 0x76B1, 0x6BB0,
0x2CB1, 0xEB1, 0xEB1, 0xEB1, 0xEB1, 0xEB1, 0x6BB0, 0xEB1,
0xEB1, 0xEB1, 0xEB1, 0x76DC, 0x76DC, 0x6BB0, 0x63B0, 0x86DC,
0x46DC, 0x48DC, 0x48DC, 0x48DC, 0x48DC, 0x40DC, 0x40DC, 0x40DC,
0x40DC, 0x40DC, 0x40DC, 0x40DC, 0x40DC, 0x60B1, 0xCB0, 0x40DC,
0x40DC, 0x40DC, 0x40DC, 0x40DC, 0x40DC, 0x40DC, 0x40DC, 0x40DC,
0x60B1, 0xCB0, 0x60B1, 0xCB0, 0xCB0, 0xCB0, 0x60B1, 0x8DC,
0x8DC, 0x8DC, 0x8DC, 0x6DC, 0x86DC, 0x87DC, 0x67DC, 0xACB1,
0xACB1, 0xACB1, 0x7DC, 0xACB1, 0x76DC, 0x7CDC, 0x76B0, 0x76B0,
0x78DC, 0x78DC, 0x76DC, 0x76B1, 0x76B1, 0x67DC, 0x67DC, 0x67DC,
0x67DC, 0x67DC, 0x67DC, 0x67DC, 0x2CB1, 0x2CB1, 0x63B0, 0x63B0,
0x63B0, 0x63B0, 0x63B0, 0x68B1, 0xC2B1, 0xC2B1, 0xC2B1, 0xC2B1,
0xC2B1, 0xC2B1, 0xC2B1, 0xC2B1, 0xC2B1, 0x63B0, 0xC2B1, 0xC2B1,
0xC2B1, 0xC2B1, 0xC2B1, 0xC2B1, 0x63B0, 0x63B0, 0x63B0, 0x63B0,
0xC2B1, 0x68B1, 0xE0B1, 0x86B0, 0x68B1, 0x24B1, 0xE0B1, 0xE0B1,
0x8DC, 0x24B1, 0x86DC, 0x24B1, 0x24B1, 0xC0B1, 0xE0B1, 0xC0B1,
0x86DC, 0x86DC, 0x86DC, 0x86DC, 0x86DC, 0x86DC, 0x86DC, 0xEB1,
0x67DC, 0x67DC, 0x67DC, 0x8EB1, 0xACB1, 0xACB1, 0x7DC, 0x7DC,
0x7DC, 0x8EB1, 0x8EB1, 0x8EB1, 0xACB1, 0x67DC, 0x67DC, 0x67DC,
0xACB1, 0x74B0, 0x7CB0, 0x76B0, 0x1EB1, 0x67B1, 0x67B1, 0xACB1,
0xACB1, 0x8EB1, 0xACB1, 0x8EB1, 0x8EB1, 0x8EB1, 0x8EB1, 0x67DC,
0xEB1, 0x63B0, 0x86DC, 0x86DC, 0x86DC, 0x86DC, 0x86DC, 0x86DC,
0xA4B1, 0xA4B1, 0xA4B1, 0xA4B1, 0x86DC, 0x86DC, 0xEB1, 0x86DC,
0x86DC, 0x86DC, 0x86DC, 0x86DC, 0x86DC, 0x86DC, 0x86DC, 0x86DC,
0x86DC, 0x86DC, 0x86DC, 0x68B1, 0xE8B1, 0x68B1, 0x2CB1, 0x86DC,
0xEB1, 0xEB1, 0xEB1, 0x67DC, 0x67DC, 0x67DC, 0x67DC, 0x67DC,
0x67DC, 0x67DC, 0x67DC, 0x70DC, 0x8EB1, 0x8EB1, 0xACB1, 0xACB1,
0x8EB1, 0x8EB1, 0xACB1, 0xACB1, 0xACB1, 0xACB1, 0x8EB1, 0xACB1,
0xACB1, 0x8EB1, 0x8EB1, 0x8EB1, 0xACB1, 0xACB1, 0xACB1, 0x76B0,
0x7CB0, 0x7CB0, 0x67B2, 0x76B0, 0x67B1, 0x86DC, 0x67DC, };
void imageDisplaySplash()
{
    imageDisplay(bob);
}

void imageDisplay(short* image)
{
    memcpy(0xB8000, image, 4000);
}