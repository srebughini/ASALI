from enum import Enum


class DataKeys(Enum):
    """
    Class to handle the keys of the data stored in DataStore
    """
    LINE_EDIT_INPUT = "line_edit_input"
    COMBO_BOX_SELECTION = "combo_box_selection"
    CHECK_BOX_STATE = "check_box_state"
    CALCULATION_RESULT = "calculation_result"
