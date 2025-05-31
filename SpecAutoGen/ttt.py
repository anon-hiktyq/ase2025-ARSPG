import openai
import argparse
import json
import re
import os

class SpecificationConvertor:

    def __init__(self):
        # OpenAI 客户端初始化
        # self.llm ='gpt-3.5-turbo'
        # self.llm ='claude-3-7-sonnet'
        # self.llm = 'deepseek-v3'
        self.llm = 'claude-3-7-sonnet-thinking'

        self.client = openai.OpenAI(
            base_url="https://yunwu.ai/v1",
            api_key="sk-hfyQZDWdgyc4oQnDw4nvOh6KT1iDQ5EbNy9UjQwnMzBntefe"
        )
        # 初始化消息列表
        self.messages = [
            {"role": "system", "content": "You are a helpful assistant."}
        ]

    def extract_last_c_code(self, text):
        # 匹配 C 代码块（Markdown 代码块 或 以 #include 开头的代码）
        code_blocks = re.findall(r'```c(.*?)```', text, re.DOTALL)  # Markdown 代码块
        return code_blocks[-1] if code_blocks else text  # 返回最后一个 C 代码块

    def inconvert_annotations(self, annotations):
        """调用大模型生成ACSL规约"""
        prompt =  self.get_inconvert_prompt(annotations)
        try:
            """调用 OpenAI API 获取 ACSL 注释"""
            # 将内容添加到消息中
            self.messages.append({"role": "user", "content": prompt})

            # 获取助手的响应
            response = self.client.chat.completions.create(
                model= self.llm,
                messages=self.messages,
                temperature=0.3
            )

            # 处理响应
            assistant_response = response.choices[0].message.content
            assistant_response = re.sub(r'>\s*Reasoning\s*[\s\S]*?(?=\n\n|$)', '', assistant_response, flags=re.IGNORECASE)
            assistant_response = re.sub(r'<think>.*?</think>', '', assistant_response, flags=re.DOTALL)
            assistant_response = self.extract_last_c_code(assistant_response)

            return assistant_response

        except Exception as e:
            print(f"API调用失败 (inconvert_annotations): {e}")
            return None

    def convert_annotations(self, annotations):
        """调用大模型生成ACSL规约"""
        prompt =  self.get_convert_prompt(annotations)
        try:
            """调用 OpenAI API 获取 ACSL 注释"""
            # 将内容添加到消息中
            self.messages.append({"role": "user", "content": prompt})

            # 获取助手的响应
            response = self.client.chat.completions.create(
                model= self.llm,
                messages=self.messages,
                temperature=0.3
            )

            # 处理响应
            assistant_response = response.choices[0].message.content
            assistant_response = re.sub(r'>\s*Reasoning\s*[\s\S]*?(?=\n\n|$)', '', assistant_response, flags=re.IGNORECASE)
            assistant_response = re.sub(r'<think>.*?</think>', '', assistant_response, flags=re.DOTALL)
            assistant_response = self.extract_last_c_code(assistant_response)

            return assistant_response

        except Exception as e:
            print(f"API调用失败 (convert_annotations): {e}")
            return None

    def get_convert_prompt(self, annotations):
        # 从文件中读取 prompt 模板
        try:
            with open("prompt/convert.txt", "r", encoding="utf-8") as file:
                prompt_template = file.read()
        except FileNotFoundError:
            print("错误: prompt/convert.txt 文件未找到。")
            return ""

        # 替换模板中的 {code} 占位符
        convert_prompt = prompt_template.format(loop_inv=annotations)
        return convert_prompt

    def get_inconvert_prompt(self, annotations):
        # 从文件中读取 prompt 模板
        try:
            with open("prompt/inconvert.txt", "r", encoding="utf-8") as file:
                prompt_template = file.read()
        except FileNotFoundError:
            print("错误: prompt/inconvert.txt 文件未找到。")
            return ""

        # 替换模板中的 {code} 占位符
        convert_prompt = prompt_template.format(func_con=annotations)
        return convert_prompt

if __name__ == "__main__":
    convertor = SpecificationConvertor()

    print("\n--- 测试 get_convert_prompt ---")
    annotations_convert = '''














'''
    prompt_convert = convertor.get_convert_prompt(annotations_convert)
    print(f"输入注解: {annotations_convert}")
    print(f"生成的 prompt:\n{prompt_convert}")

   

    # 注意：由于没有模拟 OpenAI API 的返回，直接测试 convert_annotations 和 inconvert_annotations
    # 会真正调用 API，这可能需要你的 API 密钥并且会产生费用。
    # 如果你想进行更彻底的本地测试，你需要使用 mock 来模拟 API 的响应。

    # 以下是调用实际 API 的示例（请谨慎使用）：
    # print("\n--- 测试 convert_annotations (实际 API 调用) ---")
    # annotations_to_convert_live = "loop invariant i >= 0;"
    # result_convert_live = convertor.convert_annotations(annotations_to_convert_live)
    # print(f"输入注解: {annotations_to_convert_live}")
    # print(f"转换结果:\n{result_convert_live}")

    # print("\n--- 测试 inconvert_annotations (实际 API 调用) ---")
    # annotations_to_inconvert_live = "requires balance > amount;"
    # result_inconvert_live = convertor.inconvert_annotations(annotations_to_inconvert_live)
    # print(f"输入注解: {annotations_to_inconvert_live}")
    # print(f"转换结果:\n{result_inconvert_live}")