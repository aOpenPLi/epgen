**********************************************************************
*         EPG数据转换器                                                *
*         作者：nx111	gdzdz@163.com                                *
*         2010年11月                                                   *
**********************************************************************
使用说明：

命令格式：
epgen [-i <input epgfile>] [-o <output epgfile>] [-v5|-v7|-v7be|-v7le|-xmltv ] [-bom] [-autofix 1|0] [-tvmap] [-?|-h|--help] [-d|-dd]

   -i 输入EPG数据文件,可以是ENIGMA_EPG_V7、ENIGMA_PLI_V5的BIG/LITTLE ENDIAN数据文件，也可以是xmltv数据文件(扩展名必须是.xml)，xmltv数据文件支持在channel定义的tsonid属性。除帮助模式外，必须使用此参数。
 
   -o 输出EPG数据文件，支持ENIGMA_EPG_V7、ENIGMA_PLI_V5的BIG/LITTLE ENDIAN数据文件，其中输入文件为ENIGMA_PLI_V5或xmltv文件时，将会将文字编码转换为UTF-8。如果输入文件为xmltv文件，必须在文件中使用channel的tsonid属性或提供独立完整的mvmap.dat，如果某个频道没有相应的tsonid记录，将会放弃该频道的EPG数据。
 
   -v5|-v7|-v7be|-v7le|-xmltv 输出文件的格式，v5为ENIGMA_PLI_V5（BIG ENDIAN），v7和v7be为ENIGMA_EPG_V7（BIG ENDIAN），v7le为ENIGMA_EPG_V7（BIG ENDIAN）,xmltv为xmltv文件。

   -bom 输出为xmltv时输出BOM标记，默认不输出。

   -autofix <1|0>  转换时是否自动修复数据中的错误，默认为1。
   
   -tvmap  生成tvmap.dat/tvmap_all.dat。tvmap.dat包含无重复频道名的tsonid->频道对照表，tvmap_all.dat为所有频道的tsonid->频道对照表，

   -d 调试用，载入数据文件后显示数据内容。 -dd 更多调试信息。
 
运行环境：x86平台linux、mipsel平台linux、win32。
 备注：本程序自动识别EPG数据源的ENDIAN，从而正确载入数据。再从内存中写入目标文件。载入数据后，程序会在当前目录下产生频道映射表tvmap.dat。
