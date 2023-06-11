from abc import ABC, abstractmethod
from pathlib import Path

from lib.FuncSignature import FuncSignature


class AbstractRender(ABC):
    def __init__(self, params: dict):
        self.params = params

    @abstractmethod
    def extract_func_signature(self) -> FuncSignature:
        pass

    @abstractmethod
    def get_file_name(self) -> str:
        pass

    @abstractmethod
    def get_file_path(self) -> Path:
        pass

    @abstractmethod
    def render(self) -> str:
        pass

    @abstractmethod
    def post_render(self, src_root: Path) -> None:
        pass
