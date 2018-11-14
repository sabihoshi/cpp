#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

bool in_array(const std::string &value, const std::vector<std::string> &array)
{
	return std::find(array.begin(), array.end(), value) != array.end();
}
int main()
{
	std::vector<std::vector<std::string>> arr = {{"ⓐ", "ⓑ", "ⓒ", "ⓓ", "ⓔ", "ⓕ", "ⓖ", "ⓗ", "ⓘ", "ⓙ", "ⓚ", "ⓛ", "ⓜ", "ⓝ", "ⓞ", "ⓟ", "ⓠ", "ⓡ", "ⓢ", "ⓣ", "ⓤ", "ⓥ", "ⓦ", "ⓧ", "ⓨ", "ⓩ", "ⓐ", "ⓑ", "ⓒ", "ⓓ", "ⓔ", "ⓕ", "ⓖ", "ⓗ", "ⓘ", "ⓙ", "ⓚ", "ⓛ", "ⓜ", "ⓝ", "ⓞ", "ⓟ", "ⓠ", "ⓡ", "ⓢ", "ⓣ", "ⓤ", "ⓥ", "ⓦ", "ⓧ", "ⓨ", "ⓩ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"α", "в", "¢", "∂", "є", "f", "g", "н", "ι", "נ", "к", "ℓ", "м", "и", "σ", "ρ", "q", "я", "ѕ", "т", "υ", "ν", "ω", "χ", "у", "z", "α", "в", "¢", "∂", "є", "f", "g", "н", "ι", "נ", "к", "ℓ", "м", "и", "σ", "ρ", "q", "я", "ѕ", "т", "υ", "ν", "ω", "χ", "у", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"₳", "฿", "₵", "Đ", "Ɇ", "₣", "₲", "Ⱨ", "ł", "J", "₭", "Ⱡ", "₥", "₦", "Ø", "₱", "Q", "Ɽ", "₴", "₮", "Ʉ", "V", "₩", "Ӿ", "Ɏ", "Ⱬ", "₳", "฿", "₵", "Đ", "Ɇ", "₣", "₲", "Ⱨ", "ł", "J", "₭", "Ⱡ", "₥", "₦", "Ø", "₱", "Q", "Ɽ", "₴", "₮", "Ʉ", "V", "₩", "Ӿ", "Ɏ", "Ⱬ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ᴀ", "ʙ", "ᴄ", "ᴅ", "ᴇ", "ғ", "ɢ", "ʜ", "ɪ", "ᴊ", "ᴋ", "ʟ", "ᴍ", "ɴ", "ᴏ", "ᴘ", "ǫ", "ʀ", "s", "ᴛ", "ᴜ", "ᴠ", "ᴡ", "x", "ʏ", "ᴢ", "ᴀ", "ʙ", "ᴄ", "ᴅ", "ᴇ", "ғ", "ɢ", "ʜ", "ɪ", "ᴊ", "ᴋ", "ʟ", "ᴍ", "ɴ", "ᴏ", "ᴘ", "ǫ", "ʀ", "s", "ᴛ", "ᴜ", "ᴠ", "ᴡ", "x", "ʏ", "ᴢ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"Ꭺ", "b", "Ꮯ", "Ꭰ", "Ꭼ", "f", "Ꮆ", "h", "Ꭵ", "j", "Ꮶ", "Ꮮ", "m", "Ꮑ", "Ꮎ", "Ꮲ", "q", "Ꮢ", "s", "Ꮖ", "u", "Ꮙ", "Ꮃ", "x", "Ꮍ", "Ꮓ", "Ꭺ", "b", "Ꮯ", "Ꭰ", "Ꭼ", "f", "Ꮆ", "h", "Ꭵ", "j", "Ꮶ", "Ꮮ", "m", "Ꮑ", "Ꮎ", "Ꮲ", "q", "Ꮢ", "s", "Ꮖ", "u", "Ꮙ", "Ꮃ", "x", "Ꮍ", "Ꮓ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"α", "в", "c", "d", "є", "f", "g", "h", "í", "j", "k", "l", "m", "n", "σ", "p", "q", "r", "ѕ", "t", "u", "v", "w", "х", "ч", "z", "α", "в", "c", "d", "є", "f", "g", "h", "í", "j", "k", "l", "m", "n", "σ", "p", "q", "r", "ѕ", "t", "u", "v", "w", "х", "ч", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ǟ", "ɮ", "ƈ", "ɖ", "ɛ", "ʄ", "ɢ", "ɦ", "ɨ", "ʝ", "Ꮶ", "ʟ", "ʍ", "ռ", "օ", "ք", "զ", "ʀ", "ֆ", "Ꮖ", "ʊ", "ʋ", "ա", "x", "ʏ", "ʐ", "ǟ", "ɮ", "ƈ", "ɖ", "ɛ", "ʄ", "ɢ", "ɦ", "ɨ", "ʝ", "Ꮶ", "ʟ", "ʍ", "ռ", "օ", "ք", "զ", "ʀ", "ֆ", "Ꮖ", "ʊ", "ʋ", "ա", "x", "ʏ", "ʐ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ᗩ", "ᗷ", "ᑕ", "ᗪ", "E", "ᖴ", "G", "ᕼ", "I", "ᒍ", "K", "ᒪ", "ᗰ", "ᑎ", "O", "ᑭ", "ᑫ", "ᖇ", "ᔕ", "T", "ᑌ", "ᐯ", "ᗯ", "᙭", "Y", "ᘔ", "ᗩ", "ᗷ", "ᑕ", "ᗪ", "E", "ᖴ", "G", "ᕼ", "I", "ᒍ", "K", "ᒪ", "ᗰ", "ᑎ", "O", "ᑭ", "ᑫ", "ᖇ", "ᔕ", "T", "ᑌ", "ᐯ", "ᗯ", "᙭", "Y", "ᘔ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ä", "ḅ", "ċ", "ď", "ệ", "ḟ", "ġ", "ḧ", "ï", "j", "ḳ", "ŀ", "ṃ", "ń", "ö", "ṗ", "q", "ŕ", "ṩ", "ẗ", "ü", "ṿ", "ẅ", "ẍ", "ÿ", "ẓ", "ä", "ḅ", "ċ", "ď", "ệ", "ḟ", "ġ", "ḧ", "ï", "j", "ḳ", "ŀ", "ṃ", "ń", "ö", "ṗ", "q", "ŕ", "ṩ", "ẗ", "ü", "ṿ", "ẅ", "ẍ", "ÿ", "ẓ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"Ḁ", "ḃ", "ḉ", "Ḋ", "ḕ", "ḟ", "Ḡ", "ḧ", "ḭ", "j", "Ḳ", "Ḷ", "ṁ", "Ṇ", "ṏ", "Ṗ", "q", "ṙ", "Ṡ", "Ṯ", "ṳ", "Ṽ", "ẇ", "Ẍ", "ẏ", "Ẓ", "Ḁ", "ḃ", "ḉ", "Ḋ", "ḕ", "ḟ", "Ḡ", "ḧ", "ḭ", "j", "Ḳ", "Ḷ", "ṁ", "Ṇ", "ṏ", "Ṗ", "q", "ṙ", "Ṡ", "Ṯ", "ṳ", "Ṽ", "ẇ", "Ẍ", "ẏ", "Ẓ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ａ", "ｂ", "ｃ", "ｄ", "ｅ", "ｆ", "ｇ", "ｈ", "ｉ", "ｊ", "ｋ", "ｌ", "ｍ", "ｎ", "ｏ", "ｐ", "ｑ", "ｒ", "ｓ", "ｔ", "ｕ", "ｖ", "ｗ", "ｘ", "ｙ", "ｚ", "ａ", "ｂ", "ｃ", "ｄ", "ｅ", "ｆ", "ｇ", "ｈ", "ｉ", "ｊ", "ｋ", "ｌ", "ｍ", "ｎ", "ｏ", "ｐ", "ｑ", "ｒ", "ｓ", "ｔ", "ｕ", "ｖ", "ｗ", "ｘ", "ｙ", "ｚ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ᴀ", "ʙ", "ᴄ", "ᴅ", "ᴇ", "ᴈ", "ɢ", "ʜ", "ɪ", "ᴊ", "ᴋ", "ʟ", "ᴍ", "ɴ", "ᴏ", "ᴘ", "ᴓ", "ʀ", "ᴤ", "ᴛ", "ᴜ", "ᴠ", "ᴡ", "ᴥ", "ʏ", "ᴢ", "ᴀ", "ʙ", "ᴄ", "ᴅ", "ᴇ", "ᴈ", "ɢ", "ʜ", "ɪ", "ᴊ", "ᴋ", "ʟ", "ᴍ", "ɴ", "ᴏ", "ᴘ", "ᴓ", "ʀ", "ᴤ", "ᴛ", "ᴜ", "ᴠ", "ᴡ", "ᴥ", "ʏ", "ᴢ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"α", "в", "c", "∂", "ε", "ғ", "g", "н", "ι", "נ", "к", "ℓ", "м", "η", "σ", "ρ", "q", "я", "s", "т", "υ", "v", "ω", "x", "ү", "z", "α", "в", "c", "∂", "ε", "ғ", "g", "н", "ι", "נ", "к", "ℓ", "м", "η", "σ", "ρ", "q", "я", "s", "т", "υ", "v", "ω", "x", "ү", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"卂", "乃", "匚", "ᗪ", "乇", "千", "Ꮆ", "卄", "丨", "ﾌ", "Ҝ", "ㄥ", "爪", "几", "ㄖ", "卩", "Ɋ", "尺", "丂", "ㄒ", "ㄩ", "ᐯ", "山", "乂", "ㄚ", "乙", "卂", "乃", "匚", "ᗪ", "乇", "千", "Ꮆ", "卄", "丨", "ﾌ", "Ҝ", "ㄥ", "爪", "几", "ㄖ", "卩", "Ɋ", "尺", "丂", "ㄒ", "ㄩ", "ᐯ", "山", "乂", "ㄚ", "乙", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"Ă", "β", "Č", "Ď", "Ĕ", "Ŧ", "Ğ", "Ĥ", "Ĩ", "Ĵ", "Ķ", "Ĺ", "М", "Ń", "Ő", "Р", "Q", "Ŕ", "Ś", "Ť", "Ú", "V", "Ŵ", "Ж", "Ŷ", "Ź", "Ă", "β", "Č", "Ď", "Ĕ", "Ŧ", "Ğ", "Ĥ", "Ĩ", "Ĵ", "Ķ", "Ĺ", "М", "Ń", "Ő", "Р", "Q", "Ŕ", "Ś", "Ť", "Ú", "V", "Ŵ", "Ж", "Ŷ", "Ź", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"Ꭺ", "b", "Ꮯ", "Ꭰ", "Ꭼ", "f", "Ꮆ", "h", "Ꭵ", "j", "Ꮶ", "Ꮮ", "m", "Ꮑ", "Ꮎ", "Ꮲ", "q", "Ꮢ", "s", "Ꮖ", "u", "Ꮙ", "Ꮃ", "x", "Ꮍ", "Ꮓ", "Ꭺ", "b", "Ꮯ", "Ꭰ", "Ꭼ", "f", "Ꮆ", "h", "Ꭵ", "j", "Ꮶ", "Ꮮ", "m", "Ꮑ", "Ꮎ", "Ꮲ", "q", "Ꮢ", "s", "Ꮖ", "u", "Ꮙ", "Ꮃ", "x", "Ꮍ", "Ꮓ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"Ꮧ", "Ᏸ", "ፈ", "Ꮄ", "Ꮛ", "Ꭶ", "Ꮆ", "Ꮒ", "Ꭵ", "Ꮰ", "Ꮶ", "Ꮭ", "Ꮇ", "Ꮑ", "Ꭷ", "Ꭾ", "Ꭴ", "Ꮢ", "Ꮥ", "Ꮦ", "Ꮼ", "Ꮙ", "Ꮗ", "ጀ", "Ꭹ", "ፚ", "Ꮧ", "Ᏸ", "ፈ", "Ꮄ", "Ꮛ", "Ꭶ", "Ꮆ", "Ꮒ", "Ꭵ", "Ꮰ", "Ꮶ", "Ꮭ", "Ꮇ", "Ꮑ", "Ꭷ", "Ꭾ", "Ꭴ", "Ꮢ", "Ꮥ", "Ꮦ", "Ꮼ", "Ꮙ", "Ꮗ", "ጀ", "Ꭹ", "ፚ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ɐ", "b", "ɔ", "d", "ǝ", "ɟ", "ƃ", "ɥ", "ı", "ɾ", "ʞ", "l", "ɯ", "n", "o", "d", "b", "ɹ", "s", "ʇ", "n", "ʌ", "ʍ", "x", "ʎ", "z", "ɐ", "b", "ɔ", "d", "ǝ", "ɟ", "ƃ", "ɥ", "ı", "ɾ", "ʞ", "l", "ɯ", "n", "o", "d", "b", "ɹ", "s", "ʇ", "n", "ʌ", "ʍ", "x", "ʎ", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"Δ", "β", "Ć", "Đ", "€", "₣", "Ǥ", "Ħ", "Ɨ", "Ĵ", "Ҝ", "Ł", "Μ", "Ň", "Ø", "Ƥ", "Ω", "Ř", "Ş", "Ŧ", "Ữ", "V", "Ŵ", "Ж", "¥", "Ž", "Δ", "β", "Ć", "Đ", "€", "₣", "Ǥ", "Ħ", "Ɨ", "Ĵ", "Ҝ", "Ł", "Μ", "Ň", "Ø", "Ƥ", "Ω", "Ř", "Ş", "Ŧ", "Ữ", "V", "Ŵ", "Ж", "¥", "Ž", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"α", "ɓ", "૮", "∂", "ε", "ƒ", "ɠ", "ɦ", "เ", "ʝ", "ҡ", "ℓ", "ɱ", "ɳ", "σ", "ρ", "φ", "૨", "ร", "ƭ", "µ", "ѵ", "ω", "א", "ყ", "ƶ", "α", "ɓ", "૮", "∂", "ε", "ƒ", "ɠ", "ɦ", "เ", "ʝ", "ҡ", "ℓ", "ɱ", "ɳ", "σ", "ρ", "φ", "૨", "ร", "ƭ", "µ", "ѵ", "ω", "א", "ყ", "ƶ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ᗩ", "ᗷ", "ᑕ", "ᗪ", "ᗴ", "ᖴ", "Ǥ", "ᕼ", "Ꭵ", "ᒎ", "ᛕ", "ᒪ", "ᗰ", "ᑎ", "ᗝ", "ᑭ", "Ɋ", "ᖇ", "ᔕ", "丅", "ᑌ", "ᐯ", "ᗯ", "᙭", "Ƴ", "乙", "ᗩ", "ᗷ", "ᑕ", "ᗪ", "ᗴ", "ᖴ", "Ǥ", "ᕼ", "Ꭵ", "ᒎ", "ᛕ", "ᒪ", "ᗰ", "ᑎ", "ᗝ", "ᑭ", "Ɋ", "ᖇ", "ᔕ", "丅", "ᑌ", "ᐯ", "ᗯ", "᙭", "Ƴ", "乙", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ค", "๒", "ς", "๔", "є", "Ŧ", "ﻮ", "ђ", "เ", "ן", "к", "l", "๓", "ภ", "๏", "ק", "ợ", "г", "ร", "t", "ย", "ש", "ฬ", "ץ", "א", "z", "ค", "๒", "ς", "๔", "є", "Ŧ", "ﻮ", "ђ", "เ", "ן", "к", "l", "๓", "ภ", "๏", "ק", "ợ", "г", "ร", "t", "ย", "ש", "ฬ", "ץ", "א", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"a", "в", "c", "d", "e", "ғ", "g", "н", "ι", "j", "ĸ", "l", "м", "n", "o", "p", "q", "r", "ѕ", "т", "υ", "v", "w", "х", "y", "z", "a", "в", "c", "d", "e", "ғ", "g", "н", "ι", "j", "ĸ", "l", "м", "n", "o", "p", "q", "r", "ѕ", "т", "υ", "v", "w", "х", "y", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"Ⓐ", "Ⓑ", "Ⓒ", "Ⓓ", "Ⓔ", "Ⓕ", "Ⓖ", "Ⓗ", "Ⓘ", "Ⓙ", "Ⓚ", "Ⓛ", "Ⓜ", "Ⓝ", "Ⓞ", "Ⓟ", "Ⓠ", "Ⓡ", "Ⓢ", "Ⓣ", "Ⓤ", "Ⓥ", "Ⓦ", "Ⓧ", "Ⓨ", "Ⓩ", "Ⓐ", "Ⓑ", "Ⓒ", "Ⓓ", "Ⓔ", "Ⓕ", "Ⓖ", "Ⓗ", "Ⓘ", "Ⓙ", "Ⓚ", "Ⓛ", "Ⓜ", "Ⓝ", "Ⓞ", "Ⓟ", "Ⓠ", "Ⓡ", "Ⓢ", "Ⓣ", "Ⓤ", "Ⓥ", "Ⓦ", "Ⓧ", "Ⓨ", "Ⓩ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"Ꮬ", "ℬ", "Ꮯ", "ᗬ", "℮", "ℱ", "ℊ", "ዞ", "ℹ", "Ꭻ", "ʞ", "Ꮁ", "m", "ɲ", "ñ", "⋆", "℘", "ɸ", "ℛ", "Ꮥ", "ʈ", "ʉ", "ʋ", "Ꮃ", "ℵ", "Ꮍ", "Ꮬ", "ℬ", "Ꮯ", "ᗬ", "℮", "ℱ", "ℊ", "ዞ", "ℹ", "Ꭻ", "ʞ", "Ꮁ", "m", "ɲ", "ñ", "⋆", "℘", "ɸ", "ℛ", "Ꮥ", "ʈ", "ʉ", "ʋ", "Ꮃ", "ℵ", "Ꮍ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"Ꭿ", "Ᏸ", "Ꮸ", "ᕍ", "ḕ", "ᖴ", "g", "Ᏺ", "ḭ", "Ꮷ", "ḳ", "l", "๓", "n", "ñ", "๏", "ᑬ", "q", "ᖇ", "ຮ", "t", "ᙈ", "v", "Ꮤ", "ჯ", "ẙ", "Ꭿ", "Ᏸ", "Ꮸ", "ᕍ", "ḕ", "ᖴ", "g", "Ᏺ", "ḭ", "Ꮷ", "ḳ", "l", "๓", "n", "ñ", "๏", "ᑬ", "q", "ᖇ", "ຮ", "t", "ᙈ", "v", "Ꮤ", "ჯ", "ẙ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ą", "ც", "ƈ", "ɖ", "ɛ", "ʄ", "ɠ", "ɧ", "ı", "ʝ", "ƙ", "Ɩ", "ɱ", "ŋ", "ơ", "℘", "զ", "ཞ", "ʂ", "ɬ", "ų", "۷", "ῳ", "ҳ", "ყ", "ʑ", "ą", "ც", "ƈ", "ɖ", "ɛ", "ʄ", "ɠ", "ɧ", "ı", "ʝ", "ƙ", "Ɩ", "ɱ", "ŋ", "ơ", "℘", "զ", "ཞ", "ʂ", "ɬ", "ų", "۷", "ῳ", "ҳ", "ყ", "ʑ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"a", "в", "c", "d", "e", "ғ", "g", "н", "ι", "j", "ĸ", "l", "м", "n", "o", "p", "q", "r", "ѕ", "т", "υ", "v", "w", "х", "y", "z", "a", "в", "c", "d", "e", "ғ", "g", "н", "ι", "j", "ĸ", "l", "м", "n", "o", "p", "q", "r", "ѕ", "т", "υ", "v", "w", "х", "y", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"α", "в", "c", "d", "є", "f", "g", "h", "í", "j", "k", "l", "m", "n", "σ", "p", "q", "r", "ѕ", "t", "u", "v", "w", "х", "ч", "z", "α", "в", "c", "d", "є", "f", "g", "h", "í", "j", "k", "l", "m", "n", "σ", "p", "q", "r", "ѕ", "t", "u", "v", "w", "х", "ч", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ค", "๒", "ς", "๔", "є", "ﾓ", "ﻮ", "ђ", "เ", "ן", "к", "l", "๓", "ภ", "๏", "ק", "ợ", "г", "ร", "t", "ย", "ש", "ฬ", "א", "ץ", "z", "ค", "๒", "ς", "๔", "є", "ﾓ", "ﻮ", "ђ", "เ", "ן", "к", "l", "๓", "ภ", "๏", "ק", "ợ", "г", "ร", "t", "ย", "ש", "ฬ", "א", "ץ", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"Ꭺ", "b", "Ꮯ", "Ꭰ", "Ꭼ", "f", "Ꮆ", "h", "Ꭵ", "j", "Ꮶ", "Ꮮ", "m", "Ꮑ", "Ꮎ", "Ꮲ", "q", "Ꮢ", "s", "Ꮖ", "u", "Ꮙ", "Ꮃ", "x", "Ꮍ", "Ꮓ", "Ꭺ", "b", "Ꮯ", "Ꭰ", "Ꭼ", "f", "Ꮆ", "h", "Ꭵ", "j", "Ꮶ", "Ꮮ", "m", "Ꮑ", "Ꮎ", "Ꮲ", "q", "Ꮢ", "s", "Ꮖ", "u", "Ꮙ", "Ꮃ", "x", "Ꮍ", "Ꮓ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"Д", "Ᏸ", "ℂ", "∂", "Ǝ", "ƒ", "Ꮆ", "ℍ", "î", "ʝ", "Ƙ", "ℓ", "ℳ", "И", "ø", "ρ", "Ǫ", "Я", "Ƨ", "✞", "υ", "ϑ", "Ꮤ", "✘", "У", "Հ", "Д", "Ᏸ", "ℂ", "∂", "Ǝ", "ƒ", "Ꮆ", "ℍ", "î", "ʝ", "Ƙ", "ℓ", "ℳ", "И", "ø", "ρ", "Ǫ", "Я", "Ƨ", "✞", "υ", "ϑ", "Ꮤ", "✘", "У", "Հ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"Д", "Б", "C", "D", "Ξ", "F", "G", "H", "I", "J", "Ҝ", "L", "M", "И", "Ф", "P", "Ǫ", "Я", "S", "Γ", "Ц", "V", "Щ", "Ж", "У", "Z", "Д", "Б", "C", "D", "Ξ", "F", "G", "H", "I", "J", "Ҝ", "L", "M", "И", "Ф", "P", "Ǫ", "Я", "S", "Γ", "Ц", "V", "Щ", "Ж", "У", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ǟ", "ɮ", "ƈ", "ɖ", "ɛ", "ʄ", "ɢ", "ɦ", "ɨ", "ʝ", "Ꮶ", "ʟ", "ʍ", "ռ", "օ", "ք", "զ", "ʀ", "ֆ", "Ꮖ", "ʊ", "ʋ", "ա", "x", "ʏ", "ʐ", "ǟ", "ɮ", "ƈ", "ɖ", "ɛ", "ʄ", "ɢ", "ɦ", "ɨ", "ʝ", "Ꮶ", "ʟ", "ʍ", "ռ", "օ", "ք", "զ", "ʀ", "ֆ", "Ꮖ", "ʊ", "ʋ", "ա", "x", "ʏ", "ʐ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ɑ", "ҍ", "ϲ", "ժ", "ҽ", "ƒ", "ց", "հ", "í", "յ", "Ƙ", "Ӏ", "ʍ", "ղ", "օ", "Թ", "զ", "ɾ", "Տ", "Ե", "մ", "ѵ", "ա", "×", "վ", "Հ", "ɑ", "ҍ", "ϲ", "ժ", "ҽ", "ƒ", "ց", "հ", "í", "յ", "Ƙ", "Ӏ", "ʍ", "ղ", "օ", "Թ", "զ", "ɾ", "Տ", "Ե", "մ", "ѵ", "ա", "×", "վ", "Հ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ꍏ", "ꌃ", "ꉓ", "ꀸ", "ꍟ", "ꎇ", "ꁅ", "ꃅ", "ꀤ", "ꀭ", "ꀘ", "꒒", "ꎭ", "ꈤ", "ꂦ", "ᖘ", "ꆰ", "ꋪ", "ꌗ", "꓄", "ꀎ", "ᐯ", "ꅏ", "ꊼ", "ꌩ", "ꁴ", "ꍏ", "ꌃ", "ꉓ", "ꀸ", "ꍟ", "ꎇ", "ꁅ", "ꃅ", "ꀤ", "ꀭ", "ꀘ", "꒒", "ꎭ", "ꈤ", "ꂦ", "ᖘ", "ꆰ", "ꋪ", "ꌗ", "꓄", "ꀎ", "ᐯ", "ꅏ", "ꊼ", "ꌩ", "ꁴ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ᴬ", "ᴮ", "ᶜ", "ᴰ", "ᴱ", "ᶠ", "ᴳ", "ᴴ", "ᴵ", "ᴶ", "ᴷ", "ᴸ", "ᴹ", "ᴺ", "ᴼ", "ᴾ", "ᵟ", "ᴿ", "ˢ", "ᵀ", "ᵁ", "ᵛ", "ᵂ", "ˣ", "ᵞ", "ᶻ", "ᴬ", "ᴮ", "ᶜ", "ᴰ", "ᴱ", "ᶠ", "ᴳ", "ᴴ", "ᴵ", "ᴶ", "ᴷ", "ᴸ", "ᴹ", "ᴺ", "ᴼ", "ᴾ", "ᵟ", "ᴿ", "ˢ", "ᵀ", "ᵁ", "ᵛ", "ᵂ", "ˣ", "ᵞ", "ᶻ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"α", "в", "c", "d", "e", "ғ", "ɢ", "н", "ι", "j", "ĸ", "l", "м", "ɴ", "o", "p", "q", "r", "ѕ", "т", "υ", "v", "w", "х", "y", "z", "α", "в", "c", "d", "e", "ғ", "ɢ", "н", "ι", "j", "ĸ", "l", "м", "ɴ", "o", "p", "q", "r", "ѕ", "т", "υ", "v", "w", "х", "y", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"Λ", "Ϧ", "ㄈ", "Ð", "Ɛ", "F", "Ɠ", "н", "ɪ", "ﾌ", "Қ", "Ł", "௱", "Л", "Ø", "þ", "Ҩ", "尺", "ら", "Ť", "Ц", "Ɣ", "Ɯ", "χ", "Ϥ", "Ẕ", "Λ", "Ϧ", "ㄈ", "Ð", "Ɛ", "F", "Ɠ", "н", "ɪ", "ﾌ", "Қ", "Ł", "௱", "Л", "Ø", "þ", "Ҩ", "尺", "ら", "Ť", "Ц", "Ɣ", "Ɯ", "χ", "Ϥ", "Ẕ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ƛ", "Ɓ", "Ƈ", "Ɗ", "Є", "Ƒ", "Ɠ", "Ӈ", "Ɩ", "ʆ", "Ƙ", "Լ", "M", "Ɲ", "Ơ", "Ƥ", "Ƣ", "Ʀ", "Ƨ", "Ƭ", "Ʋ", "Ɣ", "Ɯ", "Ҳ", "Ƴ", "Ȥ", "ƛ", "Ɓ", "Ƈ", "Ɗ", "Є", "Ƒ", "Ɠ", "Ӈ", "Ɩ", "ʆ", "Ƙ", "Լ", "M", "Ɲ", "Ơ", "Ƥ", "Ƣ", "Ʀ", "Ƨ", "Ƭ", "Ʋ", "Ɣ", "Ɯ", "Ҳ", "Ƴ", "Ȥ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ᕱ", "ც", "꒝", "Ꭰ", "ꂅ", "ꊰ", "g", "♅", "Ꭵ", "ϳ", "К", "լ", "ო", "ภ", "Ծ", "Ꮅ", "գ", "Ꮢ", "Ꮥ", "Ϯ", "u", "Ꮙ", "Ꮃ", "ꊼ", "Ꭹ", "Ꮓ", "ᕱ", "ც", "꒝", "Ꭰ", "ꂅ", "ꊰ", "g", "♅", "Ꭵ", "ϳ", "К", "լ", "ო", "ภ", "Ծ", "Ꮅ", "գ", "Ꮢ", "Ꮥ", "Ϯ", "u", "Ꮙ", "Ꮃ", "ꊼ", "Ꭹ", "Ꮓ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ค", "ც", "८", "ძ", "૯", "Բ", "૭", "Һ", "ɿ", "ʆ", "қ", "Ն", "ɱ", "Ո", "૦", "ƿ", "ҩ", "Ր", "ς", " ", " ", " ", " ", " ", " ", " ", "ค", "ც", "८", "ძ", "૯", "Բ", "૭", "Һ", "ɿ", "ʆ", "қ", "Ն", "ɱ", "Ո", "૦", "ƿ", "ҩ", "Ր", "ς", " ", " ", " ", " ", " ", " ", " ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"Թ", "Յ", "Շ", "Ժ", "ȝ", "Բ", "Գ", "ɧ", "ɿ", "ʝ", "ƙ", "ʅ", "ʍ", "Ռ", "Ծ", "ρ", "φ", "Ր", "Տ", "Ե", "Մ", "ע", "ա", "Ճ", "Վ", "Հ", "Թ", "Յ", "Շ", "Ժ", "ȝ", "Բ", "Գ", "ɧ", "ɿ", "ʝ", "ƙ", "ʅ", "ʍ", "Ռ", "Ծ", "ρ", "φ", "Ր", "Տ", "Ե", "Մ", "ע", "ա", "Ճ", "Վ", "Հ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ﾑ", "乃", "ᄃ", "り", "乇", "ｷ", "ム", "ん", "ﾉ", "ﾌ", "ズ", "ﾚ", "ﾶ", "刀", "の", "ｱ", "ゐ", "尺", "丂", "ｲ", "ひ", "√", "W", "ﾒ", "ﾘ", "乙", "ﾑ", "乃", "ᄃ", "り", "乇", "ｷ", "ム", "ん", "ﾉ", "ﾌ", "ズ", "ﾚ", "ﾶ", "刀", "の", "ｱ", "ゐ", "尺", "丂", "ｲ", "ひ", "√", "W", "ﾒ", "ﾘ", "乙", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"α", "ß", "ς", "d", "ε", "ƒ", "g", "h", "ï", "յ", "κ", "ﾚ", "m", "η", "⊕", "p", "Ω", "r", "š", "†", "u", "∀", "ω", "x", "ψ", "z", "α", "ß", "ς", "d", "ε", "ƒ", "g", "h", "ï", "յ", "κ", "ﾚ", "m", "η", "⊕", "p", "Ω", "r", "š", "†", "u", "∀", "ω", "x", "ψ", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ค", "๖", "¢", "໓", "ē", "f", "ງ", "h", "i", "ว", "k", "l", "๓", "ຖ", "໐", "p", "๑", "r", "Ş", "t", "น", "ง", "ຟ", "x", "ฯ", "ຊ", "ค", "๖", "¢", "໓", "ē", "f", "ງ", "h", "i", "ว", "k", "l", "๓", "ຖ", "໐", "p", "๑", "r", "Ş", "t", "น", "ง", "ຟ", "x", "ฯ", "ຊ", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, {"ɐ", "b", "ɔ", "d", "ǝ", "ɟ", "ƃ", "ɥ", "!", "ɾ", "ʞ", "ן", "ɯ", "n", "o", "d", "b", "ɹ", "s", "ʇ", "n", "ʌ", "ʍ", "x", "ʎ", "z", "ɐ", "b", "ɔ", "d", "ǝ", "ɟ", "ƃ", "ɥ", "!", "ɾ", "ʞ", "ן", "ɯ", "n", "o", "d", "b", "ɹ", "s", "ʇ", "n", "ʌ", "ʍ", "x", "ʎ", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}};
	std::vector<std::string> invalid = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", " "};
	std::ofstream file("output.txt");
	for (unsigned int i = 0; i < arr[0].size(); i++)
	{
		for (unsigned int j = 0; j < arr.size(); j++)
		{
			if (!in_array(arr[j][i], invalid))
			{
				invalid.push_back(arr[j][i]);
				file << "|" << arr[j][i];
			};
		}
		file << std::endl;
	}
}