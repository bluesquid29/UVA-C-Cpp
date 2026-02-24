
```c
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(typeof(arr[0])))

```

用上面的就好