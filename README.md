# ase2025-ARSPG
 ase2026-ARSPG-artifact 

## Project Structure

```
ARSPG/
├──sac_c_parser/
├──SpecAutoGen/
    ├── 1_input/              
    ├── 1_output/                
    ├── 2_input/               
    ├── 2_output/            
    ├── 3_output/ 
    ├── DSL/  
    ├── LoopInvGen/
    ├── SpecAutoAnnotator/    
    ├── output/             
    ├── prompt/
    ├── test/       
    ├── Config.py                             
    ├── MainProcessor.py  
    ├── SpecifactionVerify.py
    └──  Convertor.py         
```

## Code Components

### 1. Configuration Management

**File:** `Config.py`

**Purpose:** Centralizes code analysis parameters (e.g., I/O paths, preprocessing flags) for unified project control.

### 2. Main Processing Flow

**File:** `MainProcessor.py`

**Core Class:** `MainProcessor`

**Purpose:** Coordinates the entire generation process: function summary generation and generalization.

### 3. Loop Invariant Generation

**Directory:** `LoopInvGen` (`invGen.py`, `loopAnalysis.py`)

**Core Class:** `InvGenerator`

**Purpose:** Generates and verifies loop invariants via symbolic execution and verification results, supporting automatic repair to meet verification needs.

### 4. Summary Generation

**Purpose:** Utilizes the external tool `sac_c_parser` to generate relative strongest postconditions for function summary.

### 5. Summary Generalization

**Directory:** `DSL` (`AST.py`, `Q2D.py`)

**Purpose:** Parses and transforms ACSL conditions into Z3 constraints, then extracts the strongest non-redundant subset.

### 6. Prompt Templates

**Directory:** `prompt` (e.g., `gen.txt`, `regen.txt`)

**Purpose:** Text files providing instructions for LLMs to generate or repair loop invariants and ACSL annotations, defining generation rules.

### 7. Verification and Repair

**Core Class:** `OutputVerifier`，`SpecficationVerifier`

**Tools:** `frama-c`

**Purpose:** Verifies generated code for syntax and logical correctness, supporting automatic repair or adjustment of invariants.






