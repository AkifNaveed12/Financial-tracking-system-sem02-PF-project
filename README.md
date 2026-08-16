# Financial Tracking System

A comprehensive C++ desktop application for managing personal finances with features including budget planning, tax management, financial advisory, currency conversion, and bill reminders.

## 🎯 Features

### 1. **User Authentication**

- Secure login and signup system
- User credential storage
- Account management

### 2. **Budget Planner**

- Create and manage multiple budget categories
- Track spending against budget limits
- Monitor budget vs. actual spending
- Save budget data to file

### 3. **Tax Management System**

- Calculate income tax based on income brackets
- Track deductible expenses
- Generate tax summaries
- Tax planning assistance

### 4. **Financial Advisory Module**

- Personalized financial recommendations
- Asset and liability assessment
- Income and expense analysis
- Multi-category financial guidance (vehicles, real estate, education, debt)

### 5. **Currency Converter**

- Real-time currency conversion
- Support for multiple currencies
- Quick conversion calculations

### 6. **Bill Reminder**

- Set upcoming bill reminders
- Track bill due dates
- Never miss a payment deadline

## 📋 Project Structure

```
FINANCIAL TRACKING SYSTEM FINAL/
├── Financial Tracker Project (2)/
│   └── Financial Tracker Project/
│       ├── Login Page.cpp          # User authentication module
│       ├── Budget Planner.cpp      # Budget management
│       ├── tax_module.cpp          # Tax calculation
│       ├── tax_module.h            # Tax module header
│       ├── advisory_module.cpp     # Financial advisory
│       ├── advisory_module.h       # Advisory module header
│       ├── currency changer.cpp    # Currency conversion
│       ├── bill remainder.cpp      # Bill reminders
│       ├── budget_data.txt         # Budget data storage
│       ├── bills.txt               # Bill records
│       └── users.txt               # User credentials
├── tax_management_system.cpp       # Additional tax system
├── financial_advisory_file.cpp     # Additional advisory logic
├── Makefile.cpp                    # Build configuration
└── README.md                       # This file
```

## 🚀 Getting Started

### Prerequisites

- C++ Compiler (GCC, Clang, or MSVC)
- Standard C++ Library
- Text editor or IDE (VS Code, Code::Blocks, etc.)

### Installation

1. **Clone or download the repository:**

   ```bash
   git clone <repository-url>
   cd "FINANCIAL TRACKING SYSTEM FINAL"
   ```

2. **Navigate to the project directory:**

   ```bash
   cd "Financial Tracker Project (2)/Financial Tracker Project"
   ```

3. **Compile the project:**

   ```bash
   g++ "Login Page.cpp" -o financial_tracker
   ```

   Or using the Makefile:

   ```bash
   make
   ```

4. **Run the application:**
   ```bash
   ./financial_tracker
   ```
   (On Windows: `financial_tracker.exe`)

## 💻 Usage Guide

### 1. **Launch the Application**

- Run the compiled executable
- You'll be presented with a login/signup menu

### 2. **Create an Account**

- Select "Sign Up"
- Enter a new username and password
- Your credentials will be stored in `users.txt`

### 3. **Login**

- Select "Login"
- Enter your username and password
- Access the main menu

### 4. **Main Menu Options**

**Budget Planning:**

- Add budget categories
- Set budget limits
- Track spending
- View budget vs. actual comparison

**Tax Management:**

- Enter income information
- Calculate tax liability
- Review tax deductions

**Financial Advisory:**

- Grant permission to access financial data
- Input financial information (assets, income, expenses)
- Receive personalized recommendations

**Currency Converter:**

- Convert between different currencies
- Quick calculation tool

**Bill Reminder:**

- Add upcoming bills
- Set due dates
- Get reminders

## 📁 Data Storage

The application uses text files for data persistence:

- **users.txt** - User login credentials (username password pairs)
- **budget_data.txt** - Saved budget information
- **bills.txt** - Bill and reminder records

## 🛠️ Technical Details

### Key Components

- **Login Module**: Handles user authentication and account management
- **Budget Module**: Manages budget categories and spending tracking
- **Tax Module**: Calculates taxes and provides tax planning
- **Advisory Module**: Provides financial analysis and recommendations
- **Utility Functions**: Currency conversion and bill management

### Data Structures

- **Budget struct**: Stores category name, budget amount, and spent amount
- **userfinancialdata struct**: Comprehensive financial profile for advisory
- **vehicle struct**: Vehicle ownership information
- **Bill struct**: Bill information and due dates

## ⚙️ System Requirements

- **OS**: Windows, macOS, or Linux
- **Memory**: Minimum 100MB
- **Disk Space**: Minimum 10MB
- **C++ Standard**: C++11 or later

## 🔒 Security Notes

⚠️ **Important:** This is a demonstration/educational project. For production use:

- Implement password encryption (hashing)
- Use secure file storage
- Add data validation and sanitization
- Implement proper access controls
- Encrypt sensitive financial data

## 📝 Features Roadmap

- [ ] Database integration (SQLite/MySQL)
- [ ] Password encryption
- [ ] Export reports to PDF
- [ ] Multi-user support with cloud sync
- [ ] Investment tracking
- [ ] Debt management
- [ ] Net worth calculation
- [ ] Financial goal setting

## 🐛 Troubleshooting

**Issue**: Application crashes on startup

- **Solution**: Ensure all required data files (users.txt, budget_data.txt, bills.txt) are in the correct directory

**Issue**: Login fails

- **Solution**: Verify your username and password. Check that users.txt exists and contains valid entries.

**Issue**: Budget data not saving

- **Solution**: Ensure the application has write permissions to the project directory

## 📄 License

This project is provided as-is for educational purposes.

## 👨‍💻 Author

Financial Tracking System - Semester 02 Programming Fundamentals Project

## 🤝 Contributing

To contribute improvements:

1. Create a feature branch
2. Make your changes
3. Test thoroughly
4. Submit a pull request

---

**Last Updated**: 2026
**Version**: 1.0
