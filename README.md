## IOS的xcode工程编译
1. 执行abtorw命令生成xcode工程
```
  sh abtorw project xcode -DIOS -t ios open
```
2. 添加Bundle indentifier 和 Team
3. 修改Architectures 为 Standard Architectures(arm64, armv7) - $(ARCHS_STANDARD)
4. 添加命令行参数
  +  输入解析规则
  +  输入case
  +  模型文件
5. 添加资源第四步的资源文件
6. 修改Bitcode 为NO
                                                                                                                                                    
## MAC的xcode工程编译
