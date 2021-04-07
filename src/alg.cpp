// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
int d = 0;
for (int i = 0; i < len - 1; i++) {
for (int j = i + 1; j < len; j++) {
if (arr[i] + arr[j] == value) {
d++;
}
}
}
return d;
}

int countPairs2(int *arr, int len, int value) {
int l = 0, r = len - 1, d = 0;
while (r - 1 > l) {
int middle = (r + l) / 2;
if (arr[middle] <= value)
l = middle;
else
r = middle;
}
len = r-1;
for (int i = len; i >=0; i--) {
for (int j = 0; j < i; j++) {
if (arr[i] + arr[j] > value)
break;
if (arr[i] + arr[j] == value)
d++;
}
}
return d;
}

int countPairs3(int *arr, int len, int value) {
int d = 0, l = 0, r = len - 1;
while (l < r - 1) {
int middle = (l + r) / 2;
if (arr[middle] <= value)
l = middle;
else
r = middle;
}
len = r - 1;
for (int i = 0; i <len; i++) {
l = i+1, r = len-1;
int d2 = 0;
while (l < r) {
int middle = (l + r) / 2;
if (arr[middle] < (value - arr[i]))
l = middle + 1;
else
r = middle;
}
while (arr[l] == (value - arr[i])) {
d2++;
l++;
}
d += d2;
}
return d;
}
