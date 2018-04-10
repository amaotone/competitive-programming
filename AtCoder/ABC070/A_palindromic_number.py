#!/usr/bin/env python
n = input()
if n==''.join(reversed(n)):
    print('Yes')
else:
    print('No')
