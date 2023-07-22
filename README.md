# JieEngine




## 常见问题

**如果编译能通过但是VSCODE一直报未找到头文件错误,可以使用以下方法**

`Ctrl + Shift + P` 打开VSCODE Command Palette 输入 `C/C++:Edit Configurations (JSON)` 会在文件夹内自动创建一个JSON文件 找到`includePath`这个数组 把头文件路径填写上去就好了 例如:

```json
"includePath": [
    "${workspaceFolder}/JieEngine/Include/",
    "${workspaceFolder}/Test/Include/"
]
```